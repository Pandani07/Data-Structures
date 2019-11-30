#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node *rlink;
     struct node *llink;
};
struct node *temp,*start=NULL,*ptr;
void create()
{
     temp=(struct node *)malloc(sizeof(struct node));
     printf("Enter the data \n");
     scanf("%d",&temp->data);
     temp->rlink=NULL;
     temp->llink=NULL;
     if(start==NULL)
          start=temp;
     else
     {
          ptr=start;
          if(temp->data<start->data)
          {
               temp->rlink=start;
               start->llink=temp;
               start=temp;
          }
          else
          {
               while(ptr->rlink!=NULL && ptr->data<temp->data)
                    ptr=ptr->rlink;
               if(ptr->rlink==NULL && ptr->data<temp->data)
               {
                    ptr->rlink=temp;
                    temp->llink=ptr;
               }
               else
               {
                    temp->llink=ptr->llink;
                    temp->rlink=ptr;
                    ptr->llink->rlink=temp;
                    ptr->llink=temp;
               }
          }
     }
}
void  display()
{
     ptr=start;
     while(ptr!=NULL)
     {
          printf("%d",ptr->data);
          ptr=ptr->rlink;
     }
}
void main()
{
     int ch;
     while(1)
     {
          printf("Enter 1 for insertion,2 for display annd 3 for exxit");
          scanf("%d",&ch);
          switch(ch)
          {
               case 1:create();
               break;
               case 2:display();break;
               case 3:exit(0);
          }
     }
}
