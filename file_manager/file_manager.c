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
#include "current_directory.h"
#include "output_directory.h"
#include "struct_file.h"
#include "Basic_functions.h"
#include "Grafical_interface.h"

#define MAX_COUT_FILE 50

int main(int argc,char **argv)
{
  int halfx, x=3, y=2,left,right;
  int key,k=0;
  char leftcwd[255], rightcwd[255]; // Переменнные для хранение текущих директорий левого и правого подокон


  struct File f_array[MAX_COUT_FILE];


  WINDOW *wnd;                         // Переменная главного окна
  WINDOW *subwndleft, *subwndright, *subwnd;    // Переменные левого и правого подокон

  Setting_initial_parameters(); // Инициализация начальных параметров для работы с ncurses
  Create_wnd(&wnd, &subwndleft, &subwndright); // Создание основного окна и правого, левого подокон

  Output_wnd(wnd); // Вывод основного окна
  strcpy(leftcwd,Current_directory());
  strcpy(rightcwd,Current_directory());
  Output_subwnd(subwndleft, f_array,leftcwd); // Вывод левого подокна
  Output_subwnd(subwndright,f_array,rightcwd); // Вывод правого подокна
 subwnd=subwndleft;
  halfx=COLS>>1;


  keypad(wnd,true);
  wmove(wnd,y,x);

  while((key=wgetch(wnd))!=53)
  {
  mvwprintw(wnd,LINES-3,1,"key %d \n", key);
   noecho();

  switch(key)
  {

    case KEY_DOWN:

      if ((strcmp(f_array[y-1].name,"")!=0) && (y<LINES-6)) y++;
      else   if (subwnd==subwndleft) left =y; else right =y;


      break;
    case KEY_UP:
      if (y>2) y--;
      break;
    case KEY_LEFT:
    if (subwnd==subwndleft){
      if (x>2) x--;
    } else if (x>halfx+1) x--;
      break;
    case KEY_RIGHT:
      if (subwnd==subwndleft){
      if (x<halfx-2) x++;
      }else if(x<COLS-3) x++;
      break;
    case 9:
      if (subwnd==subwndleft){
        chdir(rightcwd);
        x=halfx+1;
        subwnd=subwndright;
        Output_subwnd(subwndright, f_array,rightcwd);
      }
      else {
        chdir(leftcwd);
        x=3;
        subwnd=subwndleft;
        Output_subwnd(subwndleft, f_array,leftcwd);
      }
  mvwprintw(wnd,LINES-2,1,"The current directory : %s \n", Current_directory());
    break;
    case 49:
      Create_file(subwnd);
      Output_subwnd(subwndleft, f_array,leftcwd);
      Output_subwnd(subwndright, f_array,rightcwd);
      break;
    case 50:

      if (subwnd==subwndleft){

      Read_file(subwndleft, f_array, y, leftcwd);
      strcpy(leftcwd,Current_directory());
      } else
      {
        Read_file(subwndright, f_array, y, rightcwd);
        strcpy(rightcwd,Current_directory());
      }
      y=2;

      Output_subwnd(subwnd, f_array,Current_directory());
      mvwprintw(wnd,LINES-2,1,"The current directory : %s \n", Current_directory());

      break;
    case 51:

      Write_file(subwnd, f_array, y);
      //y=2;
      Output_subwnd(subwnd, f_array,Current_directory());
      break;
    case 52:
      Creating_folder(subwnd);

      Output_subwnd(subwnd, f_array,Current_directory());
      break;
    }


   wmove(wnd,y,x);
  wrefresh(subwnd);
}

  delwin(subwndleft);
  delwin(subwnd);
  delwin(subwndright);
  delwin(wnd);


  refresh();
  endwin();
  exit(EXIT_SUCCESS);
}
