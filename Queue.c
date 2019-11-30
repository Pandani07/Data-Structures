#include<stdio.h>
#include<stdlib.h>
#define size 20
int q[size],i,f=-1,r=-1,item,ditem;
void insert()
{
     if(r==size-1)
          printf("Queue is full\n");
     else
     {
          if(f==-1)
          {
               f=0;
               r=0;
          }
          printf("Enter the element to be inserted\n");
          scanf("%d",&item);
          q[r]=item;
          r++;
          printf("%d was inserted into the queue\n",item);
     }
}
void delete()
{
     if(f==-1)
          printf("Queue is empty\n");
     else
     {
          ditem=q[f];
          printf("The deleted  item is %d\n",ditem);
          if(f==r)
          {
               f==-1;
               r==-1;
          }
          else
               f++;
     }
}
void display()
{
     if(r==-1)
          printf("The queue is empty\n");
     else
     {
          for(i=f;i<=r;i++)
          printf(" %d ",q[i]);
     }
     printf("\n");
}
void main()
{
     int ch;
     while(1)
     {
          printf("Enter your choice:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
          scanf("%d",&ch);
          switch(ch)
          {
               case 1:insert();break;
               case 2:delete();break;
               case 3:display();break;
               case 4:exit(0);
          }
     }
}
