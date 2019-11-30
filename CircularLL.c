#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node *link;
};
struct node *ptr=NULL,*last=NULL,*temp=NULL;
void create()
{
     temp=(struct node*)malloc(sizeof(struct node));
     printf("Enter the data\n");
     scanf("%d",&temp->data);
     temp->link=NULL;
}
void insert_beg()
{
     create();
     if(last==NULL)
     {
          last=temp;
          temp->link=last;
     }
     else
     {
          temp->link=last->link;
          last->link=temp;
     }
}
void insert_end()
{
     create();
     if(last==NULL)
     {
          last=temp;
          temp->link=last;
     }
     else
     {
          temp->link=last->link;
          last->link=temp;
          last=temp;
     }
}
void insert_loc()
{
     int count=0,i,loc;
     ptr=last->link;
     do
     {
          count++;
          ptr=ptr->link;
     } while(ptr!=last->link);
     printf("Enter the location\n");
     scanf("%d",&loc);
     if(loc==1)
          insert_beg();
     else if(loc==count+1)
          insert_end();
     else if(loc>1&&loc<=count)
     {
          create();
          ptr=last->link;
          for(i=1;i<loc-1;i++)
          {
               ptr=ptr->link;
          }
          temp->link=ptr->link;
          ptr->link=temp;
     }
     else
          printf("Invalid");
}
void del_beg()
{
     if(last==NULL)
          printf("Empty\n");
          else if(last->link==last)
          {
               ptr=last;
               last=NULL;
               free(ptr);
          }
     else
     {
          ptr=last->link;
          last->link=ptr->link;
          free(ptr);
     }
}
void del_end()
{
     if(last==NULL)
          printf("Empty\n");
     else
     {
          ptr=last->link;
          while(ptr!=last)
          {
               temp=ptr;
               ptr=ptr->link;
          }
          temp->link=ptr->link;
          last=temp;
          free(ptr);
     }
}
void del_loc()
{
     int count=0,pos,i;
     printf("Enter the position\n");
     scanf("%d",&pos);
     ptr=last->link;
     do
     {
         count++;
         ptr=ptr->link;
    }while(ptr!=last->link);
     if(pos==1)
         del_beg();
     else if(pos>1 && pos<=count)
     {
         ptr=last->link;
         for(i=1;i<pos;i++)
         {
             temp=ptr;
             ptr=ptr->link;
         }
         temp->link=ptr->link;
         free(ptr);
     }
     else
         printf("Invalid position\n");
}
void count()
{
     int count=0;
     ptr=last->link;
     do
     {
          ptr=ptr->link;
          count++;
     }while(ptr!=last->link);
     printf("Number of nodes is %d\n",count);
}
void search()
{
     int item,flag=0;
     ptr=last->link;
     printf("Enter the element to  be searched for\n");
     scanf("%d",&item);
     do
     {
          if(item==ptr->data)
          {
               printf("Found\n");
               flag=1;
               break;
          }
          else
               ptr=ptr->link;
     }while(ptr!=last->link);
     if(flag==0)
     {
          printf("Not found \n");
     }
}
void display()
{
     if(last==NULL)
          printf("Empty\n");
     else
     {
          ptr=last->link;
          do
          {
               printf("%d-->",ptr->data);
               ptr=ptr->link;
          }while(ptr!=last->link);
          printf("\n");
     }
}
void main()
{
     int ch;
     while(1)
     {
          printf("Enter your choice:\n1.Insert at the beginning\n2.Display\n3.Insert at the end\n4.Insert at a particular location\n5.Count nodes\n6.Search\n7.Delete first node \n8.Delete last node\n9.Delete at location\n10.Exit\n");
          scanf("%d",&ch);
          switch(ch)
          {
               case 1:insert_beg();
               break;
               case 2:display();break;
               case 3:insert_end();break;
               case 4:insert_loc();break;
               case 5:count();break;
               case 6:search();break;
               case 7:del_beg();break;
               case 8:del_end();break;
               case 9:del_loc();break;
               case 10:exit(0);
          }
     }
}
