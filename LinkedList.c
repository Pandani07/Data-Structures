#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node *link;
};
struct node *head=NULL,*ptr=NULL,*temp=NULL;
void allocate()
{
     temp=(struct node*)malloc(sizeof(struct node));
     printf("Enter the data\n");
     scanf("%d",&temp->data);
     temp->link=NULL;
}
void insert_beg()
{
     allocate();
     if(head==NULL)
          head=temp;
     else
     {
          temp->link=head;
          head=temp;
     }
}
void countnodes()
{
     int count=0;
     if(head==NULL)
          printf("List is empty\n");
     else
     {
          ptr=head;
          while(ptr!=NULL)
          {
               count++;
               ptr=ptr->link;
          }
          printf("The number of nodes is %d\n",count);
     }
}
void display()
{
     int i;
     ptr=head;
     if(head==NULL)
          printf("Linked list is empty\n");
     else
     {
          while(ptr!=NULL)
          {
               printf("%d-->",ptr->data);
               ptr=ptr->link;
          }
     }
}
void search()
{
     int item,flag=0;
     printf("Enter the element to be searched\n");
     scanf("%d",&item);
     if(head==NULL)
          printf("Linked list is empty\n");
     else
     {
          ptr=head;
          while(ptr!=NULL)
          {
               if(item==ptr->data)
               {
                    printf("The data is found\n");
                    flag=1;
                    break;
               }
               else
                    ptr=ptr->link;
          }
          if(flag==0)
               printf("Data isn't found\n");
     }
}
void insert_end()
{
     allocate();
     if(head==NULL)
          head=temp;
     else
     {
          ptr=head;
          while(ptr->link!=NULL)
               ptr=ptr->link;
          ptr->link=temp;
     }
}
void loc_base()
{
     int count=0,pos,i;
     ptr=head;
     while(ptr!=NULL)
     {
          count++;
          ptr=ptr->link;
     }
     printf("Enter the position of the node\n");
     scanf(" %d ",&pos);
     if(pos==1)
          insert_beg();
     else if(pos=count+1)
          insert_end();
     else if(pos>1&&pos<=count)
     {
          allocate();
          ptr=head;
          for(i=0;i<pos-1;i++)
               ptr=ptr->link;
          temp->link=ptr->link;
          ptr->link=temp;
     }
     else
          printf("Invalid position\n");
}
void main()
{
     int ch;
      printf("\nEnter your choice:\n1.Insert at the beginning\n2.Count the number of nodes\n3.Display\n4.Searching\n5.Insert loc \n6.Inserting at the end\n7.Exit\n");
      while(1)
      {
           scanf("%d",&ch);
           switch(ch)
           {
               case 1: insert_beg();
                       break;
               case 2: countnodes();
                       break;
               case 3: display();
                       break;
               case 4: search();
                       break;
               case 5:loc_base();
                       break;
               case 6:insert_end();break;
               case 7: exit(0);

      }
  }
}
