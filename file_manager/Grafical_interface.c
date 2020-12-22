#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <curses.h>

#include "struct_file.h"
#include "current_directory.h"
#include "output_directory.h"

void sig_winch(int signo){
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
  init_pair(1,COLOR_WHITE,COLOR_BLUE);
  wbkgd(*wnd,COLOR_PAIR(1));
  wbkgd(*subwndleft,COLOR_PAIR(1));
  wbkgd(*subwndright,COLOR_PAIR(1));
}

void Output_wnd(WINDOW * wnd){

   box(wnd,'|','#');
   mvwprintw(wnd,LINES-2,1,"The current directory : %s \n", Current_directory());
   mvwprintw(wnd,LINES-4,1,"1:New file 2:Open 3:Write file 4:New folder 5:Exit \n");
   wrefresh(wnd);
}

void Output_subwnd(WINDOW *subwnd,struct File* f_array, char *cwd){
  wclear(subwnd);
  box(subwnd,0,0);
  Output_directory(subwnd,f_array,cwd);
  wrefresh(subwnd);
}
