#include <stdio.h>
#include <string.h>


#include <stdio.h>
#define size 40
template <class T>
class st
{
    
    int st=-1;
    T a[size];
    public:
    int isempty()
    {
        if(st==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isfull()
    {
        if(st==size-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    
    }
    

    void push(T b)
    {
        if(!isfull())
        {
            st++;  
            a[st]=b;
        }

    }
    T peek()
    {
        if(!isempty())
        {
          return a[st];  
        }
    }

    T pop()
    {
        if(!isempty())
        {
           return a[st--]; 
        }
    }
};




int main()
{
    char a[30];
    int flage=1;
    st<char> s;
    printf("Enter the expression: ");
    gets(a);
    for(int i=0; a[i]!='\0'; i++)
    {
        flage=0;
        if(a[i]=='(' || a[i]=='[' || a[i]=='{')
        {
            s.push(a[i]);
        }
        else if(((a[i]==')' && s.peek()=='(') || (a[i]=='}' && s.peek()=='{') || (a[i]==']' && s.peek()=='[')) && !s.isempty() )
        {
            flage=1;
            s.pop();
        }
        else if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z') || (a[i]>='0' && a[i]<='9'))
        {
            flage=1;
        }
    }

    if(s.isempty())
    {
        if(flage==1)
        {
            printf("\nParentheses checking successfull\n");
        }
        else
        {
            printf("\nParentheses checking failed\n");
        }
       
    }
    else
    {
        printf("\nParentheses checking failed\n");  
    }

    return 0;
}