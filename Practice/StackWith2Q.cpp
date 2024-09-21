# include <stdio.h>
# define size 5

class Queue
{
    int queue[size];
    int front=-1;
    int rear=-1;

    public:

    int isEmpty()
    {
        if(rear==-1)
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
        if(rear==size-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueue(int info)
    {
        if(!isFull())
        {
            if(rear==-1)
            {
                rear++;
                front++;
            }
            else
            {
                rear++;
            }
            queue[rear]=info;
        }
    }

    int dequeue()
    {
        if(!isEmpty())
        {
            int info=queue[front];
            if(front==rear)
            {
                rear=-1;
                front=-1;
            }
            else
            {
                front++;
            }
            return info;
        }
    }
};

class StackWithQ
{
    Queue q1;
    Queue q2;
    public:

    void push(int info)
    {
        if(q1.isEmpty() && !q2.isFull())
        {
            q1.enqueue(info);

            while(!q2.isEmpty())
            {
                q1.enqueue(q2.dequeue());
            }
        }
        else if(q2.isEmpty() && !q1.isFull())
        {
            q2.enqueue(info);

            while(!q1.isEmpty())
            {
                q2.enqueue(q1.dequeue());
            }
        }
        else
        {
            printf("\nStack is full...!");
        }
    }

    int pop()
    {
        if(!q1.isEmpty())
        {
            return q1.dequeue();
        }
        else if(!q2.isEmpty())
        {
            return q2.dequeue();
        }
        else
        {
            printf("\nStack is empty...!");
        }
    }
};

int main()
{
    StackWithQ s;

    s.push(30);
    s.push(40);
    s.push(50);
    printf("\n%d",s.pop());
    printf("\n%d",s.pop());
    printf("\n%d",s.pop());
    return 0;
}