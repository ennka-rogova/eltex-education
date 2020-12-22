#include <stdio.h>
struct test{
  char name[20];
  char surname[20];
} sprav[10];
int main() {
 char str1[20], str2[20];
 int i,k=0,action,delt,exit=0;

 do {

     printf("Выбирете действие:\n 1-Добавить\n 2-Вывести список \n 3-Удалить абонент \n 4-Поиск абонента \n 5-Выйти\n");
     scanf("%d",&action);
     switch (action)
     {
     case 1:
     printf("Напишите имя и фамилию\n");
     scanf("%s%s",sprav[k].name,sprav[k].surname);
     k++;
     break;
     case 2:
     for(i=0;i<k;i++){
     printf("%d: %s %s\n",i,sprav[i].name,sprav[i].surname);
     }
     break;
     case 3:
     printf("Введите номер абонента, который хотите удалить\n");
     scanf("%d",&delt);

     for(i=delt;i<k;i++){
       sprav[i]=sprav[i+1];
     }
     k--;
     break;
     case 4:
     printf("Введите имя и фамилию абонента, которого хотите найти\n");
     scanf("%s%s",str1,str2);
      for(i=0;i<k;i++){
        if (sprav[i].name==str1) {
          printf("номер найденного абонента %d\n",i);
        };
        }

     break;
     case 5:
       exit=1;
       break;
     }

 } while(0==exit);



  return 0;
}
