//Circular Linked List

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    struct node* link;
    int info;
};typedef struct node node;

void Create_circular_list(node*);
node* Getnode();
void Display(node* head);
node* Insert_first(node*);
node* Delete_first(node*);
void Insert_last(node*);
void Delete_last(node*);
node* Insert_before(node*);
node* Delete_any(node*);

int main()
{
    node* head;
    head=(node*)malloc(sizeof(node));
    printf("\nCreation of linked list");
    head=Getnode();
    Create_circular_list(head);
    printf("\nDisplay");
    Display(head);
    printf("\nInsert first");
    head=Insert_first(head);
    Display(head);
    printf("\nDelete first node");
    head=Delete_first(head);
    Display(head);
    printf("\nInsert last");
    Insert_last(head);
    Display(head);
    printf("\nDelete last");
    Delete_last(head);
    Display(head);
    printf("\nInsert before");
    head=Insert_before(head);
    Display(head);
    printf("\nDelete any");
    head=Delete_any(head);
    Display(head);
    return 0;
}

node* Getnode()
{
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter info: ");
    scanf("%d",&newnode->info);
    return newnode;
}
void Create_circular_list(node* crrptr)
{
    char ans;
    node* newnode;
    node* first=crrptr;
    while(1)
    {
        printf("\nDo you want to enter info? ");
        fflush(stdin);
        scanf("%c",&ans);
        if(toupper(ans)=='Y')
        {
            newnode=Getnode();
            crrptr->link=newnode;
            crrptr=newnode;
        }
        else
        {
            crrptr->link=first;
            break;
        }
    }
}
void Display(node* crrptr)
{
    node* first=crrptr;
    
    do
    {
        printf("\n%d",crrptr->info);
        crrptr=crrptr->link;
    }while(crrptr!=first);
}
node* Insert_first(node* crrptr)
{
    node* newnode;
    newnode=Getnode();
    node* first = crrptr;
    while(crrptr->link!=first)
    {
        crrptr=crrptr->link;
    }
    newnode->link=first;
    crrptr->link=newnode;
    first=newnode;
    return first;
}
node* Delete_first(node* crrptr)
{
    node* first=crrptr;
    while(crrptr->link!=first)
    {
        crrptr=crrptr->link;
    }
    crrptr->link=first->link;
    first->link=NULL;
    free(first);
    return crrptr->link;
}
void Insert_last(node* crrptr)
{
    node* first=crrptr;
    node* newnode=Getnode();
    while(crrptr->link!=first)
    {
        crrptr=crrptr->link;
    }
    crrptr->link=newnode;
    newnode->link=first;
}
void Delete_last(node* crrptr)
{
    node* first=crrptr;
    while(crrptr->link->link!=first)
    {
        crrptr=crrptr->link;
    }
    free(crrptr->link);
    crrptr->link=first;
}
node* Insert_before(node* crrptr)
{
    int item;
    node* first=crrptr;
    node* newnode;
    printf("\nEnter the item:");
    scanf("%d",&item);
    if(crrptr->info==item)
    {
        newnode=Getnode();
        newnode->link=crrptr;
        while(crrptr->link!=first)
        {
            crrptr=crrptr->link;
        }
        crrptr->link=newnode;
        first=newnode;
    }
    else
    {
    while(crrptr->link!=first)
    {
        if(crrptr->link->info==item)
        {
            break;
        }
        else
        {
            crrptr=crrptr->link;
        }
    }
    if(crrptr->link->info!=item)
    {
        printf("\nNode not found");
    }
    else
    {
        newnode=Getnode();
        newnode->link=crrptr->link;
        crrptr->link=newnode;
    }
    }
    return first;
}
node* Delete_any(node* crrptr)
{
    node* first=crrptr;
    int item;
    int flage=0;
    if(crrptr!=NULL)
    {
        printf("\nEnter the info to delete: ");
        scanf("%d",&item);
        if(crrptr->info==item)
        {
            if(crrptr->link==NULL)
            {
                return NULL;
            }
            flage=1;
            crrptr=crrptr->link;
            node* temp=crrptr;
            while(crrptr->link!=first)
            {
                crrptr=crrptr->link;
            }
            first=temp;
            crrptr->link=first;
        }
        else
        {
            while(crrptr->link!=first)
            {
                if(crrptr->link->info==item)
                {
                    flage=1;
                    crrptr->link=crrptr->link->link;
                    break;
                }
                crrptr=crrptr->link;
            }
        }
       
    }
    if(flage==0)
    {
        printf("\nNode not found");
    }
    return first;
}
