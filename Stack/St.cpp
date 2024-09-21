#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int top=-1;
int stack[MAX];

void push();
void pop();
void list();

int main()
{
    int choice;
    while(1)
    {
        printf("\n\nStack operations.....");
        printf("\n1. Push\n2. Pop\n3. List\n4. Exit");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: list();
                    break;
            case 4: exit(0);
            //0 => success
            //1 => abnormal termination
        }

    }
    return 0;
}

void push()
{
    int item;
    if(top==MAX-1)
    {
        printf("\nStack overflow");
    }
    else
    {
        printf("\nEnter item to be pushed: ");
        scanf("%d",&item);
        top++;
        stack[top]=item;
    }
}
void list()
{
    int i;
    if(top==-1)
    {
        printf("\nStack is empty");
    }
    else
    {
        for(i=top; i>=0; i--)
        {
            printf("\nstack[%d]= %d",i,stack[i]);
        }
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nstack[%d]= %d",top,stack[top]);
        top--;
    }
}