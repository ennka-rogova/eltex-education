#include<stdio.h>
#include <pthread.h>
long A=0;
pthread_mutex_t mut;
void *func(void *param)
{
  long tmp;
  int i;
  int *ptr=(int*)param;
 pthread_mutex_lock(&mut);
    for(i=0;i<1000000;i++)
  {
    tmp=A;
    tmp++;
    A=tmp;
  }
  printf("thread num=%d\n",*ptr);
  pthread_mutex_unlock(&mut);
}
int main()
{
  pthread_t tid[1000];
  if (pthread_mutex_init(&mut, NULL) != 0) {

        printf("\n mutex init has failed\n");

        return 1;

    }
  int i;
  for(i=1;i<=1000;i++)
  {
    pthread_create(&tid[i-1],NULL,func,(void*)&i);
  }
  for(i=0;i<1000;i++){
    pthread_join(tid[i],NULL);
  }
   printf("%ld\n",A);
    pthread_mutex_destroy(&mut);
  return 0;
}
