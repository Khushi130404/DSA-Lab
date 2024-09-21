#include <stdio.h>
#include <string.h>

#define size 30

char stack[size];
int top=-1;

void push(char ch)
{   
    top++;
    stack[top]=ch;    
}

char pop()
{    
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int InfixPrec(char c)
{
    switch (c)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 5;
        case '(': return 9;
        case ')': return 0;
        default: return 7;
    }
}

int StackPrec(char c)
{
    switch (c)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 6;
        case '(': return 0;
        case '#': return -1;
        default: return 8;
    }
}

int Rank(char c)
{
    switch (c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return -1;    
        default: return 1;
    }
}

int Infix_Postfix(char infix[30],char postfix[30])
{
    int rank=0;
    int j=0;
    push('#');
    for(int i=0; i<strlen(infix); i++)
    {
        while(InfixPrec(infix[i])<StackPrec(peek()))
        {
            rank+=Rank(peek());
            if(rank<1)
            {
                return -1;
            }
            postfix[j++]=pop();
        }
        if(InfixPrec(infix[i])==StackPrec(peek()))
        {
            pop();
        }
        else
        {   
            push(infix[i]);
        }
    }
    while(stack[top]!='#')
    {
        rank+=Rank(peek());
        if(rank<1)
        {
            return -1;
        }
        postfix[j++]=pop();
    }
    
    postfix[j]='\0';
    return rank;
}



int main()
{
    char infix[30],postfix[30];
    printf("\nEnter the expression :");
    gets(infix);
    int rank = Infix_Postfix(infix,postfix);
    if(rank==1)
    {
        printf("\nPostfix expression : %s",postfix);
    }
    else
    {
        printf("failed...!");
    }
    return 0;
}