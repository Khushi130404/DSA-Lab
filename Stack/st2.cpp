//Write a 'c' program to implements stack using linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* link;
};typedef struct node node;

node* Getnode();
node* Push_node(node*);
node* Pop_node(node*);
void Display(node*);

int main()
{
    node* end=NULL;
    int choice;
    while(1)
    {
        printf("\nLinked list implementation of stack.....");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: end=Push_node(end);
                    break;
            case 2: end=Pop_node(end);
                    break;
            case 3: Display(end);
                    break;
            case 4:exit(0);
                    break;
        }
    }
    return 0;
}

node* Getnode()
{
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter Info: ");
    scanf("%d",&newnode->info);
    newnode->link=NULL;
    return newnode;
}
node* Push_node(node* crrptr)
{
    node* newnode = Getnode();
    if(newnode==NULL)
    {
        printf("\nStack is full , Overflow!!!");
    }
    else
    {
        newnode->link=crrptr;
        crrptr=newnode;
    }
    return crrptr;
}
node* Pop_node(node* crrptr)
{
    if(crrptr==NULL)
    {
        printf("\nStack underflow!!!");
    }
    else
    {
        printf("\nDeleted info: %d",crrptr->info);
        crrptr=crrptr->link;
    }
    return crrptr;
}
void Display(node* crrptr)
{
    while(crrptr!=NULL)
    {
        printf("\nThe info: %d",crrptr->info);
        crrptr=crrptr->link;
    }
}
