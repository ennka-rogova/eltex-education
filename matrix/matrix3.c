
#include <stdio.h>
#define N 100

int main()
{int i,n,a[N],temp;
printf("Введите размер матрицы\n");
scanf("%d",&n);
for(i=0;i<n;i++){
   scanf("%d",&a[i]);
}
printf("\nОбратная матрица\n");
for(i=0;i<n/2;i++)  
{
temp=a[i];
a[i]=a[n-i-1];
a[n-i-1]=temp;
   
}
for(i=0;i<n;i++)
 printf("%d ",a[i]);
    return 0;
}
