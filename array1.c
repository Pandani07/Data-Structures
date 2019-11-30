#include<stdio.h>
#include<stdlib.h>
#define size 30
int a[size],n,i;
void create()
{
     printf("Enter the array size \n");
     scanf("%d",&n);
     printf("Enter the elements \n");
     for(i=0;i<n;i++)
          scanf("%d",&a[i]);
}
void display()
{
     printf("The elements are:\n");
     for(i=0;i<n;i++)
          printf(" %d ",a[i]);
     printf("\n");
}
void main()
{
     int ch;
     while(1)
     {
          printf("Enter choice:\n1.Input array elements\n2.Display array elements\n");
          scanf("%d",&ch);
          switch(ch)
          {
               case 1:create();break;
               case 2:display();break;
          }
     }
}
