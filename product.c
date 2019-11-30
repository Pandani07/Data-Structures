#include<stdio.h>
int product(int a,int b)
{
     if(b>a)
          return(product(b,a));
     else if(a==0||b==0)
          return(0);
     else
          return(a+product(a,b-1));
}
void main()
{
     int a,b,res;
     printf("Enter the two numbers \n");
     scanf("%d %d",&a,&b);
     res=product(a,b);
     printf("%d X %d = %d",a,b,res);
}
