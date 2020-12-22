#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#define N 3
#define M 5
#define GOODS // Товары поставляемые погрузчиком
pthread_mutex_t mut[M];
int shop[M];
int demand[N];
// Удовлетворение спроса покупателя
void *func_get(void *param)
{

  int  curr_mut;
  int *i=(int*)param;
  curr_mut=rand()%M; // выбор случайного магазина
  pthread_mutex_lock(&mut[curr_mut]);
  if(demand[*i]>0){
  demand[*i]-=shop[curr_mut];
  shop[curr_mut]=0;
  printf("the remaining demand of goods %d of the customer %d\n", demand[*i],*i);
  sleep(2);
}
  pthread_mutex_unlock(&mut[curr_mut]);
}
// Загрузка товаров в магазин
void *func_load(void *param)
{

  int  curr_mut;
  int *i=(int*)param;
  curr_mut=rand()%M; // выбор случайного магазина
  pthread_mutex_lock(&mut[curr_mut]);
  shop[curr_mut]=shop[curr_mut]+500;
  printf("%d goods in %d shop\n", shop[curr_mut],curr_mut);
  sleep(1);

  pthread_mutex_unlock(&mut[curr_mut]);
}
int main()
{
  srand(time(NULL));
  pthread_t th_cust[N], th_load;
  int i;
  // Инициализация Mutex
  for(i=0;i<M;i++)
    if (pthread_mutex_init(&mut[i], NULL) != 0) {

        printf("\n mutex init has failed\n");

        return 1;

    }
  // Генерация запасов товаров в магазинах
  for(i=0;i<M;i++){
    shop[i]=rand()%100+450;
    printf("%d goods in %d shop\n", shop[i],i);
  }
  //Генерация необходимого спроса товаров для каждого покупателя
    for(i=0;i<N;i++){
      demand[i]=rand()%400+9800;
      printf("the required demand of goods %d of the customer %d \n", demand[i],i);
    }
 // Создание потоков покупателей
 do
 {

  for(i=0;i<N;i++)
  {
    pthread_create(&th_cust[i],NULL,func_get,(void*)&i);
  }
  // Создание потока погрузчика
    pthread_create(&th_load,NULL,func_load,(void*)&i);
}while( (demand[0]>0) || (demand[1]>0)  || (demand[2]>0) );
printf("\n stop\n");
  // Ожидание конца работы потоков покупателей и потока погрузчика
  for(i=0;i<N;i++){
    pthread_join(th_cust[i],NULL);
  }
  pthread_join(th_load,NULL);

   printf("\n");
for(i=0;i<M;i++)
    pthread_mutex_destroy(&mut[i]);
pthread_exit(NULL);
  return 0;
}
