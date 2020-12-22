#include<stdio.h>
#include"add.h"
#include"sub.h"
#include"div.h"
#include"mult.h"
int main()
{

  int quit=0,key,a,b;



  do{
    printf("\n1: Add   2: Subtraction   3: Multiplication   4: Division   5: Exit\n");
    scanf("%d",&key);
    if (5!=key){
      printf("Write the number of a, b\n");
      scanf("%d %d", &a, &b);
    }

  switch(key)
  {
    case 1:
    printf("%d+%d=%d",a,b,Add(a,b));
    break;
    case 2:
    printf("%d-%d=%d",a,b,Substraction(a,b));
    break;
    case 3:
    printf("%d*%d=%d",a,b,Multiplication(a,b));
    break;
    case 4:
    printf("%d/%d=%f",a,b,Division((float)a,b));
    break;
    case 5:
    quit=1;
    break;
  }

} while(0==quit);

return 0;
}
