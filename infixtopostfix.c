#include<stdio.h>
#include<stdlib.h>
int s[20],top=-1;
void push(char x)
{
     s[++top]=x;
}
char pop()
{
     return(s[top--]);
}
int precedence(char x)
{
     if(x=='^')
          return(4);
     else if(x=='*'||x=='/')
          return(3);
     else if(x=='-'||x=='+')
          return(2);
     else
          return(1);
}
int isop(char x)
{
     if(x=='^'||x=='/'||x=='*'||x=='+'||x=='-')
          return(1);
     else
          return(0);
}
void  main()
{
     char  *e,a,postfix[30],infix[30];
     printf("Ennter the infix expression\n");
     gets(infix);
     int j=0;
     e=infix;
     while(*e!='\0')
     {
          if(*e=='(')
               push(*e);
          else if(isalnum(*e))
               postfix[j++]=*e;
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
     printf("The postfix expression is");
     puts(postfix);
}
