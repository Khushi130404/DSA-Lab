#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cq[MAX];
int front=-1,rear=-1,cnt=0;

int Screen();
void CQInsert();
void CQDelete();
void List();

int main()
{
    int n;
    while(1)
    {
        n=Screen();
        switch(n)
        {
            case 1: CQInsert();
                    break;
            case 2: CQDelete();
                    break;
            case 3: List();
                    break;
            default: exit(0);
        }
    }
    return 0;
}

int Screen()
{
    int ch;
    printf("\nQueue operation: ");
    printf("\n1. Insert\n2. Delete\n3. List\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    return ch;
}
void CQInsert()
{
    int value;
    if((rear==MAX-1 && front==0) || (front==rear+1))
    {
        printf("\nCircular queue overflow....");
    }
    else
    {
        printf("\nEnter the number to inser: ");
        scanf("%d",&value);
        if(front==-1)
        {
            front = 0;
            rear = 0; 
        }
        else if(rear==MAX-1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        cq[rear]=value;
        cnt++;
    }
}
void List()
{
    int i,c;
    for(i=front,c=cnt; c!=0; c--,i++)
    {
        printf("\n%d",cq[i]);
        if(i==MAX-1)
        {
            i=0;
        }
    }
}
void CQDelete()
{
    if(front==-1)
    {
        printf("\nCircular queue underflow....");
    }
    else
    {
        printf("\nDeleted element: %d",cq[front]);
        cnt--;
    }
    if(front==rear)
    {
        front= -1;
        rear = -1;
    }
    else if(front==MAX-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}