#include<stdio.h>
int fact(int n)
{
     if(n==0)
          return(1);
     else
          return(n*fact(n-1));
}
void main()
{
     int n;
     printf("Enter the number\n");
     scanf("%d",&n);
     int res=fact(n);
     printf("Factorial of %d is %d\n",n,res);
}
