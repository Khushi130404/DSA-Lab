# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

struct SinglyLinkedList
{
    int info;
    struct SinglyLinkedList* link;
};
typedef struct SinglyLinkedList node;

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
            crrptr->link=NULL;
            break;
        }
    }
}

void display(node* crrptr)
{
    while(crrptr!=NULL)
    {
        printf("\n%d",crrptr->info);
        crrptr=crrptr->link;
    }
}

node* search(node* crrptr,int info)
{
    while(crrptr!=NULL)
    {
        if(crrptr->info==info)
        {
            return crrptr;
        }
        crrptr=crrptr->link;
    }
    return NULL;
}

node* delete_Any(node* crrptr,int info)
{
    node* head=crrptr;
    if(crrptr->info==info)
    {
        node* temp = crrptr;
        crrptr=crrptr->link;
        temp->link=NULL;
        free(temp);
        return crrptr;
    }
    else
    {
        while(crrptr->link!=NULL)
        {
            if(crrptr->link->info==info)
            {
                crrptr->link=crrptr->link->link;
                return head;
            }
            crrptr=crrptr->link;
        }
        printf("\nNode not found...!");
        return head;
    }
}

node* insert_Before(node* crrptr,int info)
{
    node* head = crrptr;
    if(crrptr->info==info)
    {
        node* newnode = getNode();
        newnode->link = crrptr;
        return newnode;
    }
    else
    {
        while(crrptr->link!=NULL)
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
        printf("\nNode not found...!");
        return head;
    }
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
    else
    {
        printf("\nNode not found...!");
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
