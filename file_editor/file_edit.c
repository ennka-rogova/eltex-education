#include <termios.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#define MAX_NAME_LEN 15
#define MAX_TEXT_LEN 15
void sig_winch(int signo)
{
  struct winsize size;
  ioctl(fileno(stdout),TIOCGWINSZ, (char*) &size);
  resizeterm(size.ws_row, size.ws_col);
}
int main(int argc,char **argv)
{
  int fd;  // Файловый дескриптор
  int quit=0;  // Переменная, отвечающая за выход из цикла для завершения программы
  int maxy, maxx; // Переменные длины и ширины окна
  size_t count;
  ssize_t nw;
  char name[MAX_NAME_LEN], text[MAX_TEXT_LEN];  // Объявляем переменные имени и текста файла
  WINDOW *wnd;                                  // Переменная главного окна
  WINDOW *subwndtop, *subwnddown, *subwnd12;         // Переменные центрального и нижнего подокон

  initscr();                               // Инициализируем окно
  signal(SIGWINCH,sig_winch);
  cbreak();
  curs_set(0);
  refresh();

  start_color();
  attron(A_STANDOUT);
  init_pair(1,COLOR_WHITE,COLOR_BLUE);

  getmaxyx(stdscr,maxy,maxx);  // Определяем максимальную длину и ширину окна

  wnd = newwin(maxy,maxx,0,0);  // Задаём свойства для главного окна
  wbkgd(wnd,COLOR_PAIR(1));
  wrefresh(wnd);
  box(wnd,'|','#');

  subwndtop = derwin(wnd,maxy-6,maxx-2,1,1); // Задаём свойства для центрального окна
  wbkgd(subwndtop,COLOR_PAIR(1));
  wrefresh(subwndtop);
  box(subwndtop,0,0);

  subwnddown = derwin(wnd,4,maxx-2,maxy-5,1); // Задаём свойства для нижнего окна
  box(subwnddown,0,0);
  mvwprintw(subwnddown,1,2,"1: open file    2: edit file    3: exit ");

do{
   noecho();

  switch(wgetch(wnd)) // Определяем, какие будут действия при нажатии клавиш
  {

    case 49: // Случай нажатия клавиши 1
      echo();
      mvwprintw(wnd,2,2,"Write the file name: \n");
      mvwscanw(wnd,2,25,"%s",name);
      fd = open(name,O_CREAT|O_RDWR|O_TRUNC,0777); // Открытие или создание файла
      if (fd==-1){
        perror("system call failed");
      }

      wclear(subwndtop);
      box(subwndtop,0,0);
      wrefresh(subwndtop);

      break;

    case 50: // Случай нажатия клавиши 2
      echo();
      mvwprintw(wnd,2,2, "Write the text: \n");
      mvwscanw(wnd,2,25,"%s",text);
      count=sizeof(text);
      nw = write(fd,&text,count); // Запись текста в файл
      if (nw==-1){
        perror("system call failed");
        return 1;
      }
      else if (nw!=count){
      mvwprintw(wnd,2,2,"Possible error not related to errno");
      }
      close(fd);
      wclear(subwndtop);
      box(subwndtop,0,0);
      wrefresh(subwndtop);
      break;

    case 51: // Случай нажатия клавиши 3
      quit=1;
      break;
  }
} while(0==quit);

  wrefresh(wnd);
  delwin(subwndtop);
  delwin(subwnddown);
  delwin(wnd);


  refresh();
  endwin();
  exit(EXIT_SUCCESS);
}
