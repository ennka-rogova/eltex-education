
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
#define MAX_COUT_FILE 50
void  Output_directory(WINDOW *subwnd, struct File arr[], char cwd[]){        // функция вывода текущего каталога

  struct dirent *entry = NULL;
  struct stat buf;
  DIR *dir;
  int k=0,n;

  for(int s=0;s<MAX_COUT_FILE;s++)
  for(int i=0;i<MAX_NAME_LEN ;i++){
    arr[s].name[i]=0;
  }


  dir = opendir(cwd);
  if(dir==NULL){
      perror("diropen");
      exit(1);
    };


    mvwprintw(subwnd,k+1,1,"/..");
    strcpy(arr[k].name,"/..");
    k++;

    while( (entry = readdir(dir))!=0){
      if ( (strcmp("..",entry->d_name)) && (strcmp(".",entry->d_name)))
        {
          for(int i=0;i<MAX_NAME_LEN ;i++){
            arr[k].name[i]=0;
          }
          strcpy(arr[k].name,entry->d_name);
          lstat(entry->d_name,&buf);
          if(S_ISDIR(buf.st_mode)){

            for(int i=strlen(entry->d_name);i>=0;i--)
              arr[k].name[i]=arr[k].name[i-1];
              arr[k].name[0]='/';

          }
          mvwprintw(subwnd,k+1,1,"%s",arr[k].name);

          k++;
        }
      };
      closedir(dir);
    box(subwnd,0,0);

  }
