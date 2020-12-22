#include<stdio.h>
#include <pthread.h>
long A=0;
void *func(void *param)
{
  long tmp;
  int i;
  int *ptr=(int*)param;

    for(i=0;i<1000000;i++)
  {
    tmp=A;
    tmp++;
    A=tmp;
  }
  printf("thread num=%d\n",*ptr);
}
int main()
{
  pthread_t tid[1000];

  int i;
  for(i=1;i<=1000;i++)
  {
    pthread_create(&tid[i-1],NULL,func,(void*)&i);
  }
  for(i=0;i<1000;i++){
    pthread_join(tid[i],NULL);
  }
   printf("%ld\n",A);
  return 0;
}
