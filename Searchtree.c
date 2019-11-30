#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node *rchild;
     struct node *lchild;
};
struct node *par,*curr,*temp,*root=NULL;
void make()
{
     printf("Enter the data \n");
     temp=(struct node *)malloc(sizeof(struct node));
     scanf("%d",&temp->data);
     temp->rchild=NULL;
     temp->lchild=NULL;
     if(root==NULL)
          root=temp;
     else
     {
          curr=root;
          while(curr)
          {
               par=curr;
               if(curr->data==temp->data)
               {
                    printf("Existing node \n");
                    return;
               }
               else if(curr->data<temp->data)
                    curr=curr->rchild;
               else if(curr->data>temp->data)
                    curr=curr->lchild;
          }
          if(par->data<temp->data)
               par->rchild=temp;
          else if(par->data>temp->data)
               par->lchild=temp;
     }
}
void  display(struct node *ptr)
{
     if(ptr!=NULL)
     {
          display(ptr->lchild);
          printf(" %d ",ptr->data);
          display(ptr->rchild);
     }
     printf("\n");
}
void main()
{
     int ch;
     while(1)
     {
          printf("1.Create node \n2.Display \n3.Exit\n");
          scanf("%d",&ch);
          switch(ch)
          {
               case 1:make();break;
               case 2:display(root);break;
               case 3:exit(0);
          }
     }
}
