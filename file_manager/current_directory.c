
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
char cwd[PATH_MAX];
char * Current_directory(){
if((getcwd(cwd,sizeof(cwd)))==NULL) {
    perror("getcwd() error");
    exit(1);
  }
else {

  return cwd;
  }

}
