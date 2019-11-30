#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node *llink;
     struct node *rlink;
};
struct node *ptr=NULL,*head=NULL,*temp=NULL;
void create()
{
     temp=(struct node*)malloc(sizeof(struct node));
     printf("Enter the data\n");
     scanf("%d",&temp->data);
     temp->llink=NULL;
     temp->rlink=NULL;
}
void insert_beg()
{
     create();
     if(head==NULL)
          head=temp;
     else
     {
          temp->rlink=head;
          head=temp;
     }
}
void insert_end()
{
     create();
     if(head==NULL)
          head=temp;
     else
     {
          ptr=head;
          while(ptr->rlink!=NULL)
          {
               ptr=ptr->rlink;
          }
          ptr->rlink=temp;
     }
}
void insert_loc()
{
     int count=0,i,loc;
     ptr=head;
     while(ptr!=NULL)
     {
          ptr=ptr->rlink;
          count++;
     }
     printf("Enter the location\n");
     scanf("%d",&loc);
     if(loc==1)
          insert_beg();
     else if(loc==count+1)
          insert_end();
     else if(loc>1&&loc<=count)
     {
          create();
          ptr=head;
          for(i=1;i<loc-1;i++)
          {
               ptr=ptr->rlink;
          }
          temp->llink=ptr;
          temp->rlink=ptr->rlink;
          ptr->rlink->llink=temp;
          ptr->rlink=temp;
     }
     else
          printf("Invalid");
}
void del_beg()
{
     if(head==NULL)
          printf("Empty\n");
     else
     {
          ptr=head;
          head=ptr->rlink;
          free(ptr);
          head->llink=NULL;
     }
}
void del_end()
{
     if(head==NULL)
          printf("Empty\n");
     else
     {
          ptr=head;
          while(ptr->rlink!=NULL)
          {
               ptr=ptr->rlink;
          }
          ptr->llink->rlink=NULL;
          free(ptr);
     }
}
void del_loc()
{
     int count=0,pos,i;
     printf("Enter the position\n");
     scanf("%d",&pos);
     ptr=head;
     while(ptr!=NULL)
     {
         count++;
         ptr=ptr->rlink;
     }
     if(pos==1)
         del_beg();
     else if(pos>1 && pos<=count)
     {
         ptr=head;
         for(i=1;i<pos;i++)
         {
             ptr=ptr->rlink;
         }
         ptr->llink->rlink=ptr->rlink;
         ptr->rlink->llink=ptr->llink;
         free(ptr);
     }
     else
         printf("Invalid position\n");
}
void count()
{
     int count=0;
     ptr=head;
     while(ptr!=NULL)
     {
          ptr=ptr->rlink;
          count++;
     }
     printf("Number of nodes is %d\n",count);
}
void search()
{
     int item,flag=0;
     ptr=head;
     printf("Enter the element to  be searched for\n");
     scanf("%d",&item);
     while(ptr!=NULL)
     {
          if(item==ptr->data)
          {
               printf("Found\n");
               flag=1;
               break;
          }
          else
               ptr=ptr->rlink;
     }
     if(flag==0)
     {
          printf("Not found \n");
     }
}
void display()
{
     if(head==NULL)
          printf("Empty\n");
     else
     {
          ptr=head;
          while(ptr!=NULL)
          {
               printf("%d-->",ptr->data);
               ptr=ptr->rlink;
          }
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
