#include <stdio.h>
#include <string.h>

int top=-1;
int rank=0;
char stack[50];

void push(char item)
{
    top++;
    stack[top]=item;
}
char pop()
{
    return stack[top--];
}

//Input precedence function
int inPrec(char symbol)
{
    switch(symbol)
    {
        case '+': 
        case '-': return 1;
        case '*': 
        case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default : return 7;
    }
}

//Output precedence function
int stackPrec(char symbol)
{
    switch(symbol)
    {
        case '+': 
        case '-': return 2;
        case '*': 
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        case '#': return -1;
        default : return 8;
    }
}
int Rank(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':return -1;
        default : return 1;
    }
}
int infix_postfix(char infix[50],char postfix[50])
{
    int i,j=0,length;
    char ch,temp;
    length = strlen(infix);
    push('#');
    for(i=0; i<length; i++)
    {
        ch=infix[i];
        while(inPrec(ch)<stackPrec(stack[top]))
        {
            temp=pop();
            rank+=Rank(temp);
            if(rank<1)
            {
                return -1;
            }
            postfix[j++]=temp;
        }
        if(inPrec(ch)!=stackPrec(stack[top]))
        {
            push(ch);
        }
        else
        {
            pop();
        }
    }
    while(stack[top]!='#')
    {
        temp = pop();
        rank +=Rank(temp);
        if(rank<1)
        {
            return -1;
        }
        postfix[j++]=temp;
    }
    postfix[j]='\0';
    return rank;
}
int main()
{
    char infix[50],postfix[50];
    printf("\nEnter valid infix expression: ");
    gets(infix);
    rank = infix_postfix(infix,postfix);
    if(rank==1)
    {
        printf("\nInfix to postfix: %s",postfix);
    }
    else
    {
        printf("\nFailed");
    }
    return 0;
}