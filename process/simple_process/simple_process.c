#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <stdlib.h>
int main()
{
  pid_t pid;
  pid=fork();
  if (pid>0) printf("я предок %d \n", pid);
  else if(!pid)
   printf("я младенец \n");
   else if (pid==-1)
   perror("fork");
   exit(pid);
  return 0;
}
