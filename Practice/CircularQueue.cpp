# include <stdio.h>
# define size 5

class CQueue
{
    int cq[size];
    int rear=-1,front=-1;

    public:

    int isEmpty()
    {
        if(front==-1)
        {
            printf("\nQueue underflow...!");
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isFull()
    {
        if((front==0 && rear==size-1) || front==rear+1)
        {
            printf("\nQueue overflow...!");
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueue()
    {
        if(!isFull())
        {
            int temp;
            printf("\nEnter the number to be insert : ");
            scanf("%d",&temp);
            
            if(rear==-1)
            {
                rear++;
                front++;
            }
            else if(rear==size-1)
            {
                rear=0;
            }
            else
            {
                rear++;
            }
            cq[rear]=temp;
        }
    }

    int dequeue()
    {
        if(!isEmpty())
        {
            int temp=cq[front];

            if(rear==front)
            {
                rear=-1;
                front=-1;
            }
            else if(front==size-1)
            {
                front=0;
            }
            else
            {
                front++;
            }
            return temp;
        }
    }
};

int main()
{
    CQueue cq;
    int choice=0;

    while(choice!=3)
    {
        printf("\nSelect....\n1. Insert\n2. Delete\n3. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1: cq.enqueue();
                    break;
            case 2: printf("The deleted no : %d",cq.dequeue());
        }
    }

    return 0;
}