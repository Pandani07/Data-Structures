#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node *lchild;
     struct node *rchild;
};
struct  node *root=NULL,*temp;
int is_l(struct node *ptr)
{
     int ch;
     printf("Enter your choice:\n1.Make a left child for %d\n2.No ",ptr->data);
     scanf("%d",&ch);
     if(ch==1)
          return(1);
     else
          return(0);
}
int is_r(struct node *ptr)
{
     int ch;
     printf("Enter your choice:\n1.Make a right child for %d\n2.No ",ptr->data);
     scanf("%d",&ch);
     if(ch==1)
          return(1);
     else
          return(0);
}
void createnode(struct node *ptr)
{
     if(is_l(ptr))
     {
          temp=(struct node *)malloc(sizeof(struct node));
          printf("Enter the data\n");
          scanf("%d",&temp->data);
          ptr->lchild=temp;
          createnode(temp);
     }
     else
          ptr->lchild=NULL;
     if(is_r(ptr))
     {
          temp=(struct node *)malloc(sizeof(struct node));
          printf("Enter the data\n");
          scanf("%d",&temp->data);
          ptr->rchild=temp;
          createnode(temp);
     }
     else
          ptr->rchild=NULL;
}
void inorder(struct node *ptr)
{
     if(ptr!=NULL)
     {
          inorder(ptr->lchild);
          printf(" %d ",ptr->data);
          inorder(ptr->rchild);
     }
}
void preorder(struct node *ptr)
{
     if(ptr!=NULL)
     {
          printf(" %d ",ptr->data);
          preorder(ptr->lchild);
          preorder(ptr->rchild);
     }
}
void postorder(struct node *ptr)
{
     if(ptr!=NULL)
     {
          postorder(ptr->lchild);
          postorder(ptr->rchild);
          printf(" %d ",ptr->data);
     }
}
void main()
{
     int ch;
     printf("Create the root node \n");
     root=(struct node *)malloc(sizeof(struct node));
     scanf("%d",&root->data);
     createnode(root);
     printf("\n Preorder traversal:\n");
     preorder(root);
     printf("\n Inorder traversal:\n");
     inorder(root);
     printf("\n Postorder traversal:\n");
     postorder(root);
}
