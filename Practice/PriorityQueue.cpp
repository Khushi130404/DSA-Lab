# include <stdio.h>
# define size 5

int pq[size];
int rear=-1;

int isEmpty()
{
    if(rear==-1)
    {
        printf("\nPriority queue underflow...!");
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
        printf("\nPriority queue overflow...!");
        return 1;
    }
    else
    {
        return 0;
    }
}

void check(int data)
{
    int i=0;
    for(i=0; i<rear; i++)
    {
        if(data<=pq[i])
        {
            for(int j=rear; j>i; j--)
            {
                pq[j]=pq[j-1];
            }
            break;
        }
    }
    pq[i]=data;
}

void Insert_In_Pq()
{
    if(!isFull())
    {
        int data;
        printf("\nEnter the info to insert : ");
        scanf("%d",&data);

        if(rear==-1)
        {
            rear++;
            pq[rear]=data;
        }
        else
        {
            rear++;
            check(data);
        }
    }
}

void Delete_In_Pq()
{
    if(!isEmpty())
    {
        printf("\nDeleted info : %d",pq[0]);

        for(int i=0; i<rear; i++)
        {
            pq[i]=pq[i+1];
        }
        rear--;
    }
}

int main()
{
    int choice=0;
    
    while(choice!=3)
    {
        printf("\nSelect...\n1. Insert\n2. Delete\n3. Exit");
        printf("\nEnter the choice : ",&choice);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : Insert_In_Pq();
                    break;
            case 2 : Delete_In_Pq();
        }
    }
    return 0;
}