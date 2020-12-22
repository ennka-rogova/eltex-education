#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
  pid_t p1,p2;

printf("I'm the parent, my PID is: %d \n", getpid());
p1=fork();
if (p1==0){
    p2=fork();
    if (p2>0) fork();
}
else if (p1>0) fork();

printf("pid: %d, parent: %d\n", getpid(), getppid());
sleep(2);
wait(0);
exit(0);
return 0;
}
