#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int pq[SIZE];
int front=-1,rear=-1;

void Insert_by_priority(int);
void Check(int);
void Delete_by_priority();
void Display_pq();

int main()
{
    int n,choice;
    while(choice!=4)
    {
        printf("\nScreen:-\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the value to be inserted: ");
                    scanf("%d",&n);
                    Insert_by_priority(n);
                    break;
            case 2: Delete_by_priority();
                    break;
            case 3: Display_pq();
                    break;
            case 4: exit(0);
            default: printf("\nPlease enter your choice mindfully...!");
        }
    }
    return 0;
}

void Insert_by_priority(int data)
{
    if(rear==SIZE-1)
    {
        printf("\nPQ overflow...!");
    }
    else
    {
        if(rear==-1)
        {
            rear++;
            front++;
            pq[rear]=data;
        }
        else
        {
            Check(data);
            rear++;
        }
    }
}

void Check(int data)
{
    int i,j;
    for(i=0; i<=rear; i++)
    {
        if(data>=pq[i])
        {
            for(j=rear+1; j>i; j--)
            {
                pq[j]=pq[j-1];
            }
            pq[i]=data;
            break;
        }
    }
    pq[i]=data;
}

void Display_pq()
{
    int i;
    if(front==-1)
    {
        printf("\nPQ underflow...!");
    }
    else
    {
        for(i=0; i<=rear; i++)
        {
            printf("\n%d",pq[i]);
        }
    }
}
void Delete_by_priority()
{
    int i;
    if(front==-1)
    {
        printf("\nPQ underflow...!");
    }
    else
    {
        printf("\nDeleted item: %d",pq[0]);

        for(i=0; i<=rear; i++)
        {
            pq[i]=pq[i+1];
        }
        rear--;
        if(rear==-1)
        {
            front=-1;
        }
    }
}