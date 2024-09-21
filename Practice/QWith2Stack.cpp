# include <stdio.h>
# define size 5


class Stack
{
    int stack[size];
    int top=-1;
    public:

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

    void push(int info)
    {
        if(!isFull())
        {
            stack[++top]=info;
        }
    }

    int pop()
    {
        if(!isEmpty())
        {
            return stack[top--];
        }
    }

};

class Stack2Queue
{
    Stack s1;
    Stack s2;
    public:

    void enqueue(int info)
    {
        if(s1.isEmpty() && !s2.isFull())
        {
            s2.push(info);
        }
        else if(s2.isEmpty() && !s1.isFull())
        {
            s1.push(info);
        }
        else
        {
            printf("\nQueue is full...!");
        }
    }

    int dequeue()
    {
        if(!s2.isEmpty())
        {
            while(!s2.isEmpty())
            {
                s1.push(s2.pop());
            }
            return s1.pop();
        }
        else if(!s1.isEmpty())
        {
            while(!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
            return s2.pop();
        }
        else
        {
            printf("\nQueue is empty...!");
        }
    }
};

int main()
{
    Stack2Queue s;
    s.enqueue(30);
    s.enqueue(40);
    s.enqueue(50);
    printf("\n%d",s.dequeue());
    printf("\n%d",s.dequeue());
    printf("\n%d",s.dequeue());
    return 0;
}