#include <stdio.h>
#define N 100

int main()
{int i,j,n,ntemp,a[N][N],k=0,temp=0;
printf("Введите размер матрицы\n");
scanf("%d",&n);
ntemp=n;
while(k<ntemp*ntemp)
{

  for(i=j;i<n;i++)
    a[j][i]=k++;

  for(i=j+1;i<n;i++)
    a[i][n-1]=k++;

  for(i=n-2;i>=j;i--)
  a[n-1][i]=k++;


  for(i=n-2;i>j;i--)
  a[i][j]=k++;
  
  n--;
  j++;

}



 for(int i=0;i<ntemp;i++){
    for(int j=0;j<ntemp;j++)   {
        printf("%3d ",a[i][j]);
    }
    printf("\n");
}
    return 0;
}
