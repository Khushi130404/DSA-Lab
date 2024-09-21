// Infix to postfix conversion of an expression

#include <stdio.h>
#include "stack1.cpp"
#include <string.h>

int precedence(char);
int main()
{
    printf("Enter the expression: ");
    char a[30];
    gets(a);
    st<char> s;
    for(int i=0; a[i]!='\0'; i++)
    {
        if(a[i]>='a' && a[i]<='z')
        {
            printf("%c",a[i]);
        }
        else
        {
            if(s.isempty())
            {
                s.push(a[i]);
            }
            else
            {
                if(precedence(a[i])<=precedence(s.peek()))
                {
                    printf("%c",s.pop());
                    s.push(a[i]);
                }
                else
                {
                    s.push(a[i]);
                }
            }
            
        }
    }
    while(!s.isempty())
    {
        printf("%c",s.pop());
    }
    return 0;
}

int precedence(char c)
{
    if(c=='+')
    {
        return 1;
    }
    else if(c=='-')
    {
        return 1;
    }
    else if(c=='*')
    {
        return 2;
    }
    else if(c=='/')
    {
        return 2;
    }
    else if(c=='%')
    {
        return 2;
    }
}