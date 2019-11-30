#include <stdio.h>
#include <stdlib.h>
int fibo(int);
void main()
{
     int i,j=0,n;
     printf("Enter the limit \n");
     scanf("%d",&n);
     printf("The fibonacci series is:\n");
     printf(" 0 ");
     for(i=1;i<=n;i++)
          {
               printf(" %d ",fibo(j));
               j++;
          }
}
int fibo(int j)
{
     if(j==0||j==1)
          return 1;
     else
          return(fibo(j-1)+fibo(j-2));
}
