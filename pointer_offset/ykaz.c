#include <stdio.h>

int main()
{	
int a=45645648,b;
unsigned char *ptr;
b=a;
ptr=&a;
printf("fist byte of a = %d\n", *ptr);
ptr++;
printf("second byte of a = %d\n", *ptr);
ptr++;
printf("third byte of a = %d\n", *ptr);
ptr=ptr+1;
printf("fourth byte of a = %d\n", *ptr);

ptr=&b;

printf("fist byte of a = %d\n", *ptr);
ptr++;

printf("second byte of a = %d\n", *ptr);
ptr++;
*ptr=5;
printf("third byte of a = %d\n", *ptr);
ptr++;

printf("fourth byte of a = %d\n", *ptr);

  return 0;
}
