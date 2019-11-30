#include<stdio.h>
#include<ctype.h>
#include<stdio.h>
int s[30],top=-1;
void push(int m)
{
     s[++top]=m;
}
int pop()
{
     int m;
     m=s[top];
     top--;
     return(m);
}
void main()
{
     int i,m,res,op1,op2;
     char *e,postfix[30];
     printf("Enter the postfix expression \n");
     gets(postfix);
     e=postfix;
     while(*e!='\0')
     {
          if(isalpha(*e))
          {
               printf("Enter the value of %c",*e);
               scanf("%d",&m);
               push(m);
          }
          else
          {
               op2=pop();
               op1=pop();
               switch(*e)
               {
                    case '^':res=pow(op1,op2);break;
                    case '*':res=op1*op2;break;
                    case '/':res=op1/op2;break;
                    case '+':res=op1+op2;break;
                    case '-':res=op1-op2;break;
               }
               push(res);
          }
          e++;
     }
     printf("The evaluated expression is: %d \n",pop());
}
