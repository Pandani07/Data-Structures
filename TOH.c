#include<stdio.h>
void toh(int n,char source,char temp,char dest)
{
     if(n==1)
          printf("Move disk 1 from %c to %c\n",source,dest);
     else
     {
          toh(n-1,source,dest,temp);
          printf("Move disk %d from %c to %c\n",n,source,dest);
          toh(n-1,temp,source,dest);
     }
}
void main()
{
     int n;
     printf("Enter the number of disks\n");
     scanf("%d",&n);
     toh(n,'A','B','C');
}
