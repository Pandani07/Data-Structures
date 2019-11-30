#include<stdio.h>
#include<stdlib.h>
#define size 30
int s[size],top=-1,i,item,ditem,ch;
void push()
{
     printf("Enter the element to be pushed\n");
     scanf("%d",&item);
     if(top==size-1)
          printf("Stack is full\n");
     else
     {
          s[++top]=item;
          printf("\n%d was pushed into the stack\n",item);
     }
}
void pop()
{
     if(top==-1)
          printf("Stack is empty\n");
     else
     {
          ditem=s[top];
          top--;
          printf("%d was popped\n",ditem);
     }
}
void display()
{
     if(top==-1)
          printf("Stack is empty \n");
     else
     {
          for(i=0;i<=top;i++)
               printf(" %d ",s[i]);
     }
}
void main()
{
     while(1)
     {
          printf("Enter your choice:\n1.Push\n2.Pop\n3.Display\n4.Exit");
          scanf("%d",&ch);
          switch(ch)
          {
               case 1:push();break;
               case 2:pop();break;
               case 3:display();break;
               case 4:exit(0);
          }
     }
}
