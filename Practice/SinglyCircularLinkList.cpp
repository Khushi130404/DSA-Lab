# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

struct SinglyCircularLinkList
{
    int info;
    struct SinglyCircularLinkList* link;
};
typedef struct SinglyCircularLinkList node;

node* getNode()
{
    node* newnode = (node*)malloc(sizeof(node));
    printf("\nEnter the info : ");
    scanf("%d",&newnode->info);
    newnode->link=NULL;
    return newnode;
}

void create_Link_List(node* crrptr)
{
    node* first=crrptr;
    node* newnode;
    char ans;
    while(1)
    {
        printf("\nDo you want to continue ? ");
        fflush(stdin);
        scanf("%c",&ans);
        if(toupper(ans)=='Y')
        {
            newnode = getNode();
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

void display(node* crrptr)
{
    node* first=crrptr;
    do
    {
        printf("\n%d",crrptr->info);
        crrptr=crrptr->link;
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
        crrptr=crrptr->link;
    }while(crrptr!=first);
    return NULL;
}

node* delete_Any(node* crrptr,int info)
{
    node* head=crrptr;
    node* first=crrptr;
    while(crrptr->link!=first)
    {
        if(crrptr->link->info==info)
        {
            crrptr->link=crrptr->link->link;
            return head;
        }
        crrptr=crrptr->link;
    }
    if(crrptr->link->info==info)
    {
        crrptr->link=crrptr->link->link;
        return crrptr->link;
    }
    printf("\nNode not found...!");
    return head;
    
}

node* insert_Before(node* crrptr,int info)
{
    node* head = crrptr;
    while(crrptr->link!=head)
    {
        if(crrptr->link->info==info)
        {
            node* newnode = getNode();
            newnode->link=crrptr->link;
            crrptr->link = newnode;
            return head;
        }
        crrptr=crrptr->link;
    }
    if(crrptr->link->info==info)
    {
        node* newnode = getNode();
        newnode->link=crrptr->link;
        crrptr->link=newnode;
        return newnode;
    }
    printf("\nNode not found...!");
    return head;
}

void insert_After(node* crrptr,int info)
{
    crrptr = search(crrptr,info);

    if(crrptr!=NULL)
    {
        node* newnode = getNode();
        newnode->link=crrptr->link;
        crrptr->link=newnode;
    }
}

int main()
{
    node* head= getNode();
    create_Link_List(head);
    display(head);
    int info;
    // printf("\nEnter the info to delete : ");
    // scanf("%d",&info);
    // head = delete_Any(head,info);
    // display(head);
    // printf("\nEnter the info to insert before : ");
    // scanf("%d",&info);
    // head = insert_Before(head,info);
    // display(head);
    printf("\nEnter the node to insert after : ");
    scanf("%d",&info);
    insert_After(head,info);
    display(head);
     return 0;
}
