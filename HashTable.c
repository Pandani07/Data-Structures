#include<stdio.h>
#include<stdlib.h>
int size;
int arr[100];
void init(int arr[]){
      int i;
      for(i=0;i<size;i++)
            arr[i]=-1;
}
void insert(){
      int value;
      printf("Enter the value to be inserted\n");
      scanf("%d",&value);
      int key=value%size;
      if(arr[key]==-1)
            {
                  arr[key]=value;
                  printf("Added value= %d to position arr[%d] \n",value,key);
            }
            else
            {
                  printf("Collision: arr[%d] has an element %d already!\n",key,arr[key]);
                  printf("Unable to insert\n");
            }
}
void display(){
      int i;
      for(i=0;i<size;i++)
            printf(" %d ",arr[i]);
}
void search(){
      int value;
      printf("Enter the value to be searched\n");
      int key=value%size;
      if(arr[key]==value)
            printf("%d exists in the HashTable\n");
      else
            printf("Doesnt exist\n");
}
void delete(){
      int value,ditem;
      printf("Enter the value to be deleted\n");
      scanf("%d",&value);
      int key=value%size;
      if(arr[key]==-1)
            printf("%d isnt present in the HashTable\n",value);
      else
      {
            ditem=arr[key];
            arr[key]=-1;
            printf("%d was removed from the HashTable\n",ditem);
      }
}
void main(){
      printf("Enter the size of the HashTable\n");
      scanf("%d",&size);
      init(arr);
      int ch;
      printf("Enter choice:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
      while(1){
            scanf("%d",&ch);
            switch(ch){
                  case 1:insert();break;
                  case 2:delete();break;
                  case 3:display();break;
                  case 4:search();break;
                  case 5:exit(0);
            }
      }
}
