# include <stdio.h>
# include <string.h>
# define size 30

template <class T>
class stack
{
    T s[size];
    int top=-1;

    public:

    int isFull()
    {
        if(top==size-1)
        {
            return 1;
        }   
        else
        {
            return 0;
        }
    }

    int isEmpty()
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

    void push(T info)
    {
        if(!isFull())
        {
            top++;
            s[top] = info;            
        }
    }

    T pop()
    {
        if(!isEmpty())
        {
            return s[top--];
        }
    }

    T peek()
    {
        if(!isEmpty())
        {
            return s[top];
        }
    }

};

int main()
{
    char exp[50];
    printf("\nEnter an expression : ");
    gets(exp);
    int flag=1;
    stack <char> s;
    for(int i=0; i<strlen(exp); i++)
    {
        flag=0;
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            s.push(exp[i]);
        }
        else if(((exp[i]==')' && s.peek()=='(') || (exp[i]=='}' && s.peek()=='{') || (exp[i]==']' && s.peek()=='[')) && !s.isEmpty())
        {
            flag=1;
            s.pop();
        }
        else if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z') || (exp[i]>='0' && exp[i]<='9'))
        {
            flag=1;
        }
    }

    if(s.isEmpty() && flag==1)
    {        
        printf("successful...!");
    }
    else
    {
        printf("\nFail...!");
    }
    return 0;
}