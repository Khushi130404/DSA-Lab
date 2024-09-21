//Simple Queue

#include <stdio.h>
#define SIZE 10
class queue
{
    int front=-1;
    int rear=-1;
    int arr[SIZE];
    public:

    int isempty()
    {
        if(front==-1)
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
        if(rear==SIZE-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void insert()
    {
        if(isfull())
        {
            printf("\nQueue overflow.....");
        }
        else
        {
            rear++;
            printf("\nEnter the number to insert: ");
            scanf("%d",&arr[rear]);
        }
    }
    void delet()
    {
        if(isempty())
        {
            printf("\nQueue underflow.....");
        }
        else
        {
            front++;
            printf("\narr[%d]= %d",front,arr[front]);
        }
    }
    void peek()
    {
        if(isempty())
        {
            printf("\nQueue underflow.....");
        }
        else
        {
            printf("\narr[%d]= %d",front+1,arr[front+1]);
        }
    }
};

int main()
{
    int n=0;
    queue q;
    while(n!=4)
    {
        printf("\n\nEnter choice:-\n1. Insert\n2. Delete\n3. Peek\n4. Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: q.insert();
                    break;
            case 2: q.delet();
                    break;
            case 3: q.peek();
                    break;
            case 4: break;
        }
    }
    return 0;
}