#include <stdio.h>

class stack
{
    int st=-1;
    int a[10];
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
        if(st==9)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    
    }
    

    void push()
    {
        if(isfull())
        {
            printf("Stack overflow\n");
        }
        else
        {
            st++;
            printf("Enter the number: ");
            scanf("%d",&a[st]);
        }
    }
    void peek()
    {
        if(isempty())
        {
            printf("\nStack empty");
        }
        else
        {
            printf("%d\n",a[st]);
        }  
    }

    void pop()
    {
        if(isempty())
        {
            printf("Stack empty");
        }
        else
        {
          st--;
          printf("%d",a[st+1]);  
        }
    }
};


int main()
{
    int n=0;
    stack s;
    while(n!=4)
    {
        printf("\nEnter 1 for push\nEnter 2 for pop\nEnter 3 for peek\nEnter 4 for exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: s.push();
                    break;
            case 2: s.pop();
                    break;
            case 3: s.peek();
                    break;
            case 4: break;
            default: printf("\nInvalid Input");    
                    break;    
        }
    }
    return 0;
}