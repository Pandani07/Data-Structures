#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int s[20],top=-1;
void push(int m)
{
     s[++top]=m;
}
int pop()
{
     return(s[top--]);
}
void main()
{
     int ch,op1,op2,res;
     char *e,postfix[30];
     printf("Enter postfix exp");
     gets(postfix);
     e=postfix;
     while(*e!='\0')
     {
          if(isalpha(*e))
          {
               printf("Enter the value for %c \n",*e);
               scanf("%d",&ch);
               push(ch);
          }
          else
          {
               op2=pop();
               op1=pop();
               switch(*e)
               {
                    case '*':res=op1*op2;break;
                    case '^':res=pow(op1,op2);break;
                    case '-':res=op1-op2;break;
                    case '+':res=op1+op2;break;
                    case '/':res=op1/op2;break;
               }
               push(res);
          }
          e++;
     }
     printf("Postfix eval is %d",pop());
}
