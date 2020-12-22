#include<stdio.h>
#include<stdlib.h>
typedef struct test{
  char name[20];
  char surname[20];
  char number[20];
  struct test *next;
} sprav;

int main(){
    sprav *head=NULL,*p=NULL,*t;
    int i,k=0,action,exit=0,delete;
    char str1[20],str2[20];

    head=(sprav*)malloc(sizeof(sprav));
    do {

        printf("Выбирете действие:\n 1-Добавить\n 2-Вывести список \n 3-Удалить абонент \n 4-Поиск номера абонента \n 5-Выйти\n");
        scanf("%d",&action);
        switch (action)
        {
        case 1:
          //  Add();

          p=head;
          for(i=0;i<k;i++){
              p=p->next;
            }
            p->next=(sprav*)malloc(sizeof(sprav));
            printf("Напишите имя и фамилию\n");
            scanf("%s%s",p->name,p->surname);
            printf("Напишите номер телефон\n");
            scanf("%s",&p->number);
            k++;
            break;
        case 2:
            //  List(*head);
            p=head;
            for(i=0;i<k;i++){
                printf("%d: %s %s %s\n",i+1,p->name,p->surname, p->number);
                p=p->next;
              }
            break;
        case 3:
        //  Delete(*head);
          printf("Введите номер абонента, который хотите удалить\n");
          scanf("%d",&delete);
          t=head;
          if (1==delete){
            p=head;
            head=head->next;
            free(p);
          }else
          {
          for(i=0;i<delete-2;i++){
              t=t->next;
          }
          p=t->next;
          t->next=p->next;
            free(p);
          }
            k--;
          break;
        case 4:
        //  Find();
        printf("Введите имя и фамилию абонента, которого хотите найти\n");
        scanf("%s %s",str1,str2);
        p=head;
              for(i=0;i<k;i++){
                printf("%s %s\n",str1, p->name);
                if ( (0==strcmp(p->name,str1)) && (0==strcmp(p->name,str2)) ) {
                  printf("номер найденного абонента %s\n",p->number);
                };
                p=p->next;
              }
          break;
        case 5:
          exit=1;
          break;
        }

    } while(0==exit);

  return 0;
}
