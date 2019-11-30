#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int table[500];
void shifttable(char pat[])
{
    int i,j,m;
    m=strlen(pat);
    for(i=0;i<500;i++)
        table[i]=m;
    for(j=0;j<m-1;j++)
    {
       i=pat[j];
       table[i]=m-1-j;
    }
}
int horspool(char text[],char pat[])
{
    int i,j,k,m,n;
    n=strlen(text);
    m=strlen(pat);
    printf("Length of text is %d and length of pattern is %d \n",n,m);
    i=m-1;
    while(i<=n)
    {
        k=0;
        while((k<=m)&&(text[i-k]==pat[m-1-k]))
            k++;
        if(k==m)
            return(i-m+1);
        else
            {
                j=text[i];
                i+=table[j];
            }
    }
    return(-1);
}
void main()
{
    char text[20],pat[20];
    int pos;
    printf("Enter the text \n");
    gets(text);
    printf("Enter the pattern\n");
    gets(pat);
    shifttable(pat);
    pos=horspool(text,pat);
    if(pos>=0)
        printf("DEsired pattern was found at %d ",pos+1);
    else
        printf("not found\n");
}
