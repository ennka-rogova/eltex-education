#include <stdio.h>

void Output(int a) // Вывод 16-ого числа 
{
unsigned char c;
for(int i=3;i>=0;i--)
	{
	c=a>>i*8;
	printf("%x ",c);
	}
}

void main()
{
int a=0x00DDAABB;
Output(a);
printf("\nTransformation:\n");
a=a^ 0x00110000; // Операция изменения 3-го байта
Output(a);

}
