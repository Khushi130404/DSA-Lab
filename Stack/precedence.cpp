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
    int peek()
    {
        if(!isempty())
        {
          return a[st];  
        }
    }

    int pop()
    {
        if(!isempty())
        {
           return a[st--]; 
        }
    }
};





int precedence(char);
int operation(int,int,char);

int  main()
{
    st <int> oprnd;
    st <char> oprt;
    char a[50];
    printf("Enter the expression: ");
    scanf("%[^\n]",a);
    
    for(int i=0 ; a[i]!='\0'; i++)
    {
        if(a[i]=='(')
        {
            oprt.push(a[i]);
        }
        
        else if(a[i]>='0' && a[i]<='9')
        {
            oprnd.push(a[i]-'0');
        }
        else if(a[i]==')')
        {
            while(oprt.peek()!='(')
            {
                char c = oprt.pop();
                int a = oprnd.pop();
                int b = oprnd.pop();
                oprnd.push(operation(b,a,c));
            }
            oprt.pop();
        }
        
       else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')
        {
        
            while(!oprt.isempty() && oprt.peek()!='(' && precedence(a[i])<=precedence(oprt.peek()))
            {
            
                char c = oprt.pop();
                int a = oprnd.pop();
                int b = oprnd.pop();
                oprnd.push(operation(b,a,c));
            }
            oprt.push(a[i]);
        }
        
    }
    
     while(!oprt.isempty())
        {
            
            char c = oprt.pop();
            int a = oprnd.pop();
            int b = oprnd.pop();
            oprnd.push(operation(b,a,c));
        }    


    printf("Tne Ans: %d",oprnd.peek());

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
    else if(c=='(')
    {
        return 3;
    }

}
int operation(int x,int y,char c)
{
    if(c=='+')
    {
        return (x+y);
    }
    else if(c=='-')
    {
        return (x-y);
    }
    else if(c=='*')
    {
        return (x*y);
    }
    else if(c=='/')
    {
        return (x/y);
    }
} 