//Write a program to perform insert and delete routines on a Queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
static int rear=-1,front=-1;
char ch;
int Q[MAX];
void screen();
void list();
void Qinsert();
void Qdelete();

int main()
{
    while(1)
    {
        screen();
        switch(ch)
        {
            case 1: Qinsert();
                    break;
            case 2: Qdelete();
                    break;
            case 3: list();
                    break;
            default: exit(0);
        }
    }
    return 0;
}

void screen()
{
    printf("\nQueue operation: ");
    printf("\n1. Insert\n2. Delete\n3. List\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
}
void Qinsert()
{
    int item;
    if(rear==MAX-1)
    {
        printf("\nQueue is full");
    }
    else
    {
        printf("Enter the info: ");
        scanf("%d",&item);
        if(rear==-1)
        {
            rear++;
            front++;
        }
        else
        {
            rear++;
        }
        Q[rear]=item;
    }
}
void Qdelete()
{
    int item;
    if(rear==-1)
    {
        printf("\nQueue is empty....");
    }
    else
    {
        item=Q[front];
        printf("\nDeleted item: %d",item);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
    }
}
void list ()
{
    if(front==-1)
    {
        printf("\nQueue is empty.....");
    }
    else
    {
        for(int i=front; i<=rear; i++)
        {
            printf("\nQ[%d]: %d",i,Q[i]);
        }
    }
   
}