#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *root=NULL,*temp;
int is_lchild(struct node *branch)
{
    int ch;
    printf("Do you want to create a lchild for %d \n",branch->data);
    printf("Enter 1 for yes, 2 for no\n");
    scanf("%d",&ch);
    if(ch==1)
        return(1);
    else
        return(0);
}
int is_rchild(struct node *branch)
{
    int ch;
    printf("Do you want to create a rchild for %d \n",branch->data);
    printf("Enter 1 for yes, 2 for no\n");
    scanf("%d",&ch);
    if(ch==1)
        return(1);
    else
        return(0);
}
void create(struct node *branch)
{
    if(is_lchild(branch))
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data \n");
        scanf("%d",&temp->data);
        branch->lchild=temp;
        create(temp);
    }
    else
        branch->lchild=NULL;
    if(is_rchild(branch))
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data \n");
        scanf("%d",&temp->data);
        branch->rchild=temp;
        create(temp);
    }
    else
        branch->rchild=NULL;
}
void inorder(struct node *branch)
{
    if(branch!=NULL)
    {
        inorder(branch->lchild);
        printf("%d\n",branch->data);
        inorder(branch->rchild);
    }
}
void preorder(struct node *branch)
{
    if(branch!=NULL)
    {
        printf("%d\n",branch->data);
        preorder(branch->lchild);
        preorder(branch->rchild);
    }
}
void postorder(struct node *branch)
{
    if(branch!=NULL)
    {

        postorder(branch->lchild);
        postorder(branch->rchild);
        printf("%d\n",branch->data);
    }
}
void main()
{
    int ch;
    printf("Create the root node\n");
    root=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the root node \n");
    scanf("%d",&root->data);
    create(root);
    printf("The inorder travel display is \n");
    inorder(root);
    printf("The preorder travel display is \n");
    preorder(root);
    printf("The postorder travel display is \n");
    postorder(root);
}
