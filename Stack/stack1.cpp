
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


