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

#include <dirent.h>
#include <string.h>



void sig_winch(int signo)
  {
    struct winsize size;
    ioctl(fileno(stdout),TIOCGWINSZ, (char*) &size);
    resizeterm(size.ws_row, size.ws_col);
  }
void Setting_initial_parameters(){
  signal(SIGWINCH,sig_winch); // Обработка сигнала SIGWINCH - вызываемый при изменении размера окна

  if (!initscr()) // Проверка и инициализация ncurses
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }
  cbreak(); // Включение режима частичного контроля над клавиатурой
  start_color(); // Подключение функции для работы с цветом окон и текста
  attron(A_STANDOUT); // Атрибут, который улучшает подсветку экрана
}
void Create_wnd(WINDOW **wnd, WINDOW ** subwndleft, WINDOW ** subwndright){ // Создание основного окна, правого и левого подокон
int halfx;
  halfx = COLS>>1; // Определение половины экрана, COLS - число столбцов
  *wnd = newwin(LINES,COLS,0,0);
  *subwndleft = derwin(*wnd,LINES-5,halfx-1,1,1); // LINES - число строк
  *subwndright = derwin(*wnd,LINES-5,halfx-1,1,halfx);

}
void Draw_wnd(WINDOW * wnd){


   init_pair(1,COLOR_WHITE,COLOR_BLUE);
   wbkgd(wnd,COLOR_PAIR(1));
   box(wnd,'|','#');
   //mvwprintw(wnd,LINES-2,1,"The current directory : %s \n", Current_directory());
   mvwprintw(wnd,LINES-4,1,"1:New file 2:Open 3:Write file 4:New folder 5:Exit \n");
   wrefresh(wnd);
}
void Draw_subwnd(WINDOW *subwnd){
  init_pair(1,COLOR_WHITE,COLOR_BLUE);
  wbkgd(subwnd,COLOR_PAIR(1));
  box(subwnd,0,0);
  wrefresh(subwnd);

//  Output_directory(subwnd,f_array,Current_directory());
}
int main()
{



  WINDOW *wnd;                         // Переменная главного окна
  WINDOW *subwndleft, *subwndright, *subwnd;    // Переменные левого и правого подокон




Setting_initial_parameters();
Create_wnd(&wnd, &subwndleft, &subwndright);

Draw_wnd(wnd);
Draw_subwnd(subwndleft);
Draw_subwnd(subwndright);



 wgetch(wnd);
 delwin(subwndleft);
 delwin(subwnd);
 delwin(subwndright);
 delwin(wnd);


 refresh();
 endwin();
 exit(EXIT_SUCCESS);
}
