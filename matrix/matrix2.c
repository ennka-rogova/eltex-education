
#include <stdio.h>
#define N 100

int main()
{int n,a[N][N];
printf("Введите размер матрицы\n");
scanf("%d",&n);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
       if(j>=n-i-1) 
            a[i][j]=1;
        else a[i][j]=0;
        printf("%d ",a[i][j]);
    }
    printf("\n");
}

    return 0;
}
