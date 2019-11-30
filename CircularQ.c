#include<stdio.h>
#include<stdlib.h>
#define size 30
int q[size],i,f=-1,r=-1,item,ditem;
void insert()
{
     if(r==(r+1)%size)
          printf("Full queue\n");
     else
     {
          if(f==-1)
          {
               f=0;

          }
          printf("Enter item to be inserted\n");
          scanf("%d",&item);
          r=(r+1)%size;
          q[r]=item;
     }
}
void delete()
{
     if(f==-1)
          printf("Empty queue\n");
     else
     {
          ditem=q[f];
          printf("%d was deleted \n",ditem);
          if(f==r)
          {
               f=-1;
               r=-1;
          }
          f=(f+1)%size;
     }
}
void display()
{
     if(f<=r)
          for(i=f;i<=r;i++)
               printf(" %d ",q[i]);
     else if(f>r)
     {
          for(i=f;i<size;i++)
               printf("%d",q[i]);
          for(i=0;i<=r;i++)
               printf("%d",q[i]);
     }
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
               case 1:insert();
               break;
               case 2:delete();
               break;
               case 3:display();
               break;
               case 4:exit(0);
          }
     }
}
