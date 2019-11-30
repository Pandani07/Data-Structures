#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int s[30],top=-1;
void push(char item)
{
     s[++top]=item;
}
char pop()
{
     return(s[top--]);
}
int precedence(char item)
{
     if(item=='^')
          return(5);
     else if(item=='*'||item=='/')
          return(4);
     else if(item=='+'||item=='-')
          return(3);
     else
          return(2);
}
int isop(char item)
{
     if(item=='^'||item=='*'||item=='/'||item=='+'||item=='-')
          return(1);
     else
          return(0);
}
void main()
{
     char infix[30],postfix[30],*e,a;
     int j=0;
     printf("Enter the infix expression\n");
     gets(infix);
     e=infix;
     while(*e!='\0')
     {
          if(isalnum(*e))
               postfix[j++]=*e;
          else if(*e=='(')
               push(*e);
          else if(isop(*e))
          {
               if(*e!='^')
                    while(top!=-1&&precedence(s[top])>=precedence(*e))
                         postfix[j++]=pop();
                    push(*e);
          }
          else if(*e==')')
          {
               while((a=pop())!='(')
                    postfix[j++]=a;
          }
          e++;
     }
     while(top!=-1)
          postfix[j++]=pop();
     postfix[j]='\0';
     printf("The evaluated expression is: ");
     puts(postfix);
}
