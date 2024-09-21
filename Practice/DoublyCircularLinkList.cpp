# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

struct DoublyCircularLinkedList
{
    int info;
    struct DoublyCircularLinkedList* next;
    struct DoublyCircularLinkedList* prev;
};
typedef struct DoublyCircularLinkedList node;

node* getNode()
{
    node* newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the info : ");
    scanf("%d",&newnode->info);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void create(node* head)
{
    char ans;
    node* crrptr=head;

    while(1)
    {
        printf("\nDo you want to continue ? ");
        fflush(stdin);
        scanf("%c",&ans);
        if(toupper(ans)=='Y')
        {
            node* newnode = getNode();
            newnode->prev = crrptr;
            newnode->next=NULL;
            crrptr->next = newnode; 
            crrptr = newnode;
        }
        else
        {
            crrptr->next=head;
            head->prev=crrptr;
            break;
        }
    }
}

void display_Forward(node* crrptr)
{
    node* first=crrptr;
    printf("\nForward...");
    do
    {
        printf("\n%d",crrptr->info);
        crrptr=crrptr->next;
    }while(crrptr!=first);
}

void display_Backward(node* crrptr)
{
    node* first=crrptr;
    printf("\nBackward...");
    do
    {
        printf("\n%d",crrptr->info);
        crrptr=crrptr->prev;
    }while(crrptr!=first);
}

node* search(node* crrptr,int info)
{
    node* first=crrptr;
    do
    {
        if(crrptr->info==info)
        {
            return crrptr;
        }
        crrptr=crrptr->next;
    }while(crrptr!=first);
    return NULL;
}

node* delete_Any(node* crrptr,int info)
{
    node* first=crrptr;
    crrptr = search(crrptr,info);

    if(crrptr==NULL)
    {
        printf("\nNode not found...!");
        return first;
    }
    else if(crrptr->next==first && crrptr->prev==first)
    {
        return NULL;
    }
    else if(crrptr==first)
    {
        node* temp = crrptr;
        crrptr=crrptr->next;
        crrptr->prev=temp->prev;
        temp->prev->next=crrptr;
        temp->next=NULL;
        temp->prev=NULL;
        free(temp);
        return crrptr;
    }
    else 
    {
        crrptr->prev->next=crrptr->next;
        crrptr->next->prev=crrptr->prev;
        return first;
    }
}

node* insert_Before(node* crrptr,int info)
{
    node* first=crrptr;
    crrptr = search(crrptr,info);

    if(crrptr==NULL)
    {
        printf("\nNode not found...!");
        return first;
    }
    else
    {
        node* newnode = getNode();
        if(crrptr==first)
        {
            crrptr->prev->next=newnode;
            newnode->prev=crrptr->prev;
            newnode->next=crrptr;
            crrptr->prev=newnode;
            return newnode;
        }
        else
        {
            crrptr->prev->next=newnode;
            newnode->prev=crrptr->prev;
            newnode->next=crrptr;
            crrptr->prev=newnode;
            return first;
        }
    }
}

void insert_After(node* crrptr,int info)
{
    node* first = crrptr;
    crrptr = search(crrptr,info);

    if(crrptr==NULL)
    {
        printf("\nNode not found...!");
    }
    else
    {
        node* newnode = getNode();
        crrptr->next->prev=newnode;
        newnode->next=crrptr->next;
        crrptr->next=newnode;
        newnode->prev=crrptr;
    } 
}

int main()
{
    node* head = getNode();
    create(head);
    display_Forward(head);
    display_Backward(head);
    int info;

    // printf("\nEnter the node to delete : ");
    // scanf("%d",&info);
    // head = delete_Any(head,info);
    // display_Forward(head);
    // display_Backward(head);

    // printf("\nEnter the info to insert before : ");
    // scanf("%d",&info);
    // head = insert_Before(head,info);
    // display_Forward(head);
    // display_Backward(head);

    printf("\nEnter the info to insert after : ");
    scanf("%d",&info);
    insert_After(head,info);
    display_Forward(head);
    display_Backward(head);
    return 0;
}