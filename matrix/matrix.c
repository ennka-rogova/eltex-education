

#include <stdio.h>
#include <malloc.h>
int main()
{
    int n,i,j;
    int **a;
    printf("Введите размера массива\n");
    scanf("%d",&n);
    a = (int**) malloc(n* sizeof(int*));
    for (i = 0; i < n; i++) {
    a[i] = (int*) malloc((i + 1) * sizeof(int));
    }
    
   
    for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
        a[i][j]=j+1+i*n;
        printf("%d ",a[i][j]);
    }
    printf("\n");
    }
    
    return 0;
}
