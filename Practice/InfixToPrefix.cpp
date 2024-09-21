# include <stdio.h>
# include <string.h>
# define size 30

char stack[size];
int top=-1;

void push(char ch)
{   
    stack[++top]=ch;    
}

char pop()
{    
    return stack[top--];
}

char peek()
{
    return stack[top];
}


int precedence(char c)
{
    switch (c)
    {
        case '+': 
        case '-': return 1;
        case '*':
        case '%':
        case '/': return 3;
        case '^': return 5;
    }
}

int precStack(char c)
{
    switch (c)
    {
        case '+': 
        case '-': return 2;
        case '*':
        case '%':
        case '/': return 2;
        case '^': return 4;
        case ')': return 0;
        case '#': return -1;
    }
}


void Infix_To_Prefix(char infix[50],char prefix[50])
{
    infix = strrev(infix);
    int j=0;
    push('#');

    for(int i=0; i<strlen(infix); i++)
    {
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
        {
            prefix[j++]=infix[i];
        }
        else if(infix[i]==')')
        {
            push(infix[i]);
        }
        else if(infix[i]=='(')
        {
            while(peek()!=')')
            {
                prefix[j++]=pop();
            }
            pop();
        }
        else
        {
            while(precStack(peek())>=precedence(infix[i]))
            {
                prefix[j++]=pop();
            }
            push(infix[i]);
        }
    }
    while(peek()!='#')
    {
        if(peek()!=')' && peek()!='(')
        {
            prefix[j++]=pop();
        }
        else
        {
            pop();
        }
    }
    prefix[j]='\0';
    prefix = strrev(prefix);
}

int main()
{
    char infix[50],prefix[50];
    printf("\nEnter expression : ");
    gets(infix);
    Infix_To_Prefix(infix,prefix);
    printf("\nPrefix : %s",prefix);
    return 0;
}