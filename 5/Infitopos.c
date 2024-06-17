#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char stack[max];
char infix[max];
char postfix[max];
int top=-1,j=0;
void push(char);
char pop();
void inftopos();
int space(char);
int isempty();
void print();
int precedence(char);
int main()
{
    printf("enter the infix expressions : ");
    gets(infix);
    inftopos();
    print();
    return 0;
}
void inftopos()
{
    char symbol,next;
    for(int i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        if(!space(symbol))
        {
            switch(symbol)
            {
                case '(':
                {
                    push(symbol);
                    break;
                }
                case ')':
                {
                    while((next=pop())!='(')
                    {
                        postfix[j++]=next;
                    }
                    break;
                }
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                {
                    while(!isempty() && precedence(stack[top]    )>=precedence(symbol))
                    {
                        postfix[j++]=pop();
                    }
                    push(symbol);
                    break;
                }
                default:
                {
                    postfix[j++]=symbol;
                    break;
                }
            }
        }
    }
    while(!isempty())
    {
        postfix[j++]=pop();
    }
    postfix[j++]='\0';
}
int space(char c)
{
    if(c==' ' || c=='\t')
        return 1;
    else
        return 0;
}
void push(char symbol)
{
    if(top==max-1)
    {
        printf("stack overflow...");
    }
    else
    {
        top+=1;
        stack[top]=symbol;
    }
}
char pop()
{
    char c=stack[top];
    top-=1;
    return c;
}
int isempty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char symbol)
{
    switch(symbol)
    {
        case '*':
        case '/':
        {
            return 2;
            break;
        }
        case '^':
        {
            return 3;
            break;
        }
        case '+':
        case '-':
        {
            return 1;
            break;
        }
        default:
        {
            return 0;
            break;
        }
    }
}
void print()
{
    int i=0;
    printf("The equivalent postfix expression is :");
    for(int i=0;i<strlen(postfix);i++)
    {
        printf("%c",postfix[i]);
    }
}
output:
enter the infix expressions : 8*(9*5/10)+20-15
The equivalent postfix expression is :895*10/*20+15-
