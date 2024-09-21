# include <stdio.h>
# define size 5

int rear=-1;

struct priorityQueueNode
{
    int info;
    int priority;
}pq[size];

int isEmpty()
{
    if(rear==-1)
    {
        printf("\nPQ is empty...!");
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
        printf("\nPQ is full...!");
        return 1;
    }
    else
    {
        return 0;
    }
}

int highestPriority()
{
    int maxPrio=pq[0].priority;

    for(int i=0; i<=rear; i++)
    {
        if(maxPrio<pq[i].priority)
        {
            maxPrio=pq[i].priority;
        }
    }
    return maxPrio;
}

void PQInsert()
{
    if(!isFull())
    {
        rear++;
        printf("\nEnter the info and priority : ");
        scanf("%d %d",&pq[rear].info,&pq[rear].priority);
    }
}

void PQDelete()
{
    if(!isEmpty())
    {
        int maxPrio=highestPriority();
        int info;
        for(int i=0; i<=rear; i++)
        {
            if(maxPrio==pq[i].priority)
            {
                info=pq[i].info;
                while(i<rear)
                {
                    pq[i].info=pq[i+1].info;
                    pq[i].priority=pq[i+1].priority;
                    i++;
                }
                break;
            }
        }
        rear--;
        printf("\n Deleted info : %d",info);
    }
}

int main()
{
    int n=0;
    while(n!=4)
    {
        scanf("\n%d",&n);
        switch (n)
        {
        case 1: PQInsert();
                break;
        case 2: PQDelete();
                break;
        case 3: printf("\n%d",highestPriority());
                break;
        default:
            break;
        }
    }
    return 0;
}