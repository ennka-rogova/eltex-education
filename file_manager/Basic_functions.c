
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "struct_file.h"
#include "current_directory.h"
#define MAX_FOLDER_LEN 15



void Create_file(WINDOW *subwnd){  // Создание файла
  int fd;
  char filename[255];
  echo();
  wclear(subwnd);
  mvwprintw(subwnd,1,1,"Write the file name: \n");
  box(subwnd,0,0);
  wrefresh(subwnd);
  mvwscanw(subwnd,1,22,"%s",filename);

  fd = open(filename,O_CREAT,0777);
  if (fd==-1){
    perror("system call failed");
  }
  close(fd);
}

void Creating_folder(WINDOW *subwnd) // Создание каталога
{
  int result;
  char name[MAX_FOLDER_LEN];
  echo();
  wclear(subwnd);
  mvwprintw(subwnd,1,1,"Write the folder name: \n");
  box(subwnd,0,0);
  wrefresh(subwnd);

  mvwscanw(subwnd,1,25,"%s",name);
  result=mkdir(name,S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
  if (result!=0) {mvwprintw(subwnd,1,1,"can't create the folder");}

}

void Read_file(WINDOW *subwnd, struct File *arr, int y, char cwd[]){ // Открытие каталога или чтение файла
  int fd,n;
  int s;
  ssize_t ret;
  char ch;



  if (strcmp(arr[y-2].name,"/..")==0){

      chdir("..");
      }
  else if (arr[y-2].name[0]=='/'){
          if((opendir(cwd))==NULL){  // Проверяем можно ли открыть каталог
            perror("diropen");
            exit(1);
          } else {
            n=strlen(arr[y-2].name);
            strncat(cwd,arr[y-2].name,n);
            chdir(cwd);
          }
        }
  else
  {
    wclear(subwnd);
    box(subwnd,0,0);
    fd = open(arr[y-2].name,O_RDONLY);
    if (fd<0){
      perror("system call failed\n");
      }
    else if ((ret=read(fd,&ch,1))<0){
        perror("Cannot read file\n");
        exit(1);
    }else{
    //  mvwprintw(subwnd,1,s,"sdfsd");
      s=1;
      while((ret=read(fd,&ch,1))>0){
        mvwprintw(subwnd,1,s,"sdfsd");
       mvwprintw(subwnd,3,s,"%s",ch); //найти другую функцию чтения
       wrefresh(subwnd);
        s++;
      }
    }

wgetch(subwnd);
      close(fd);
  }





}

void Write_file(WINDOW *subwnd, struct File *arr, int y){ // Редактирование файла
  int fd,n,s;
  ssize_t ret;
  ssize_t nw;
  char ch, text[255];
  echo();
  wclear(subwnd);
  box(subwnd,0,0);

  if (strcmp(arr[y-2].name,"/")!=0)
  {

    fd = open(arr[y-2].name,O_WRONLY|O_TRUNC,0777);
    if (fd==-1){
      perror("system call failed\n");
    }
    else{
      echo();
        mvwprintw(subwnd,1,1, "Write the text: \n");
        mvwscanw(subwnd,1,25,"%s",text);

        nw = write(fd,&text,sizeof(text)); // Запись текста в файл
        if (nw==-1){
          perror("system call failed");
        }
        else if (nw!=sizeof(text)){
        mvwprintw(subwnd,1,1,"Possible error not related to errno");
        }
        close(fd);
    }


}






}
