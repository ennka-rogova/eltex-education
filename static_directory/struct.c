#include <stdio.h>
struct test{
  char a;
  int b;
}__attribute__((packed));
int main() {
  struct test *my_test;
  char str[10]={'A',0,0,0,0,'B',0,0,0,0};
  my_test=&str;


 printf("\n%c%d",my_test->a,my_test->b);
 my_test=my_test+1;
printf("%c%d\n",my_test->a,my_test->b);
  return 0;
}
