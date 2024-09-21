# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

struct DoublyLinkedList
{
    int info;
    struct DoublyLinkedList* next;
    struct DoublyLinkedList* prev;
};
typedef struct DoublyLinkedList node;

node* getNode()
{
    node* newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the info : ");
    scanf("%d",&newnode->info);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

node* create(node* right,node* left)
{
    char ans;
    node* crrptr=left;

    while(1)
    {
        printf("\nDo you want to continue ? ");
        fflush(stdin);
        scanf("%c",&ans);
        if(toupper(ans)=='Y')
        {
            node* newnode = getNode();
            newnode->prev = crrptr;
            newnode->next = NULL;
            crrptr->next = newnode; 
            crrptr = newnode;
        }
        else
        {
            return crrptr;
        }
    }
}

void display_Forward(node* crrptr)
{
    printf("\nForward...");
    while(crrptr!=NULL)
    {
        printf("\n%d",crrptr->info);
        crrptr=crrptr->next;
    }
}

void display_Backward(node* crrptr)
{
    printf("\nBackward...");
    while(crrptr!=NULL)
    {
        printf("\n%d",crrptr->info);
        crrptr=crrptr->prev;
    }
}

node* search(node* crrptr,int info)
{
    if(crrptr->prev==NULL)
    {
        while(crrptr!=NULL)
        {
            if(crrptr->info==info)
            {
                return crrptr;
            }
            crrptr=crrptr->next;
        }
        return NULL;
    }
    else if(crrptr->next==NULL)
    {
        while(crrptr!=NULL)
        {
            if(crrptr->info==info)
            {
                return crrptr;
            }
            crrptr=crrptr->prev;
        }
        return NULL;
    }
    else
    {
        return NULL;
    }
}

node* delete_Any(node* crrptr,int info)
{
    node* left=crrptr;
    crrptr = search(crrptr,info);

    if(crrptr==NULL)
    {
        printf("\nNode not found...!");
        return left;
    }
    else if(crrptr->next==NULL && crrptr->prev==NULL)
    {
        return NULL;
    }
    else if(crrptr->prev==NULL)
    {
        crrptr->next->prev=NULL;
        node* temp = crrptr;
        crrptr=crrptr->next;
        temp->next=NULL;
        free(temp);
        return crrptr;
    }
    else if(crrptr->next==NULL)
    {
        node* temp = crrptr;
        crrptr=crrptr->prev;
        crrptr->next=NULL;
        temp->prev=NULL;
        free(temp);
        return crrptr;
    }
    else 
    {
        crrptr->prev->next=crrptr->next;
        crrptr->next->prev=crrptr->prev;
        crrptr->prev=NULL;
        crrptr->next=NULL;
        return left;
    }
}

node* insert_Before(node* crrptr,int info)
{
    node* left=crrptr;
    crrptr = search(crrptr,info);

    if(crrptr==NULL)
    {
        printf("\nNode not found...!");
        return left;
    }
    else
    {
        node* newnode = getNode();
        if(crrptr->prev==NULL)
        {
            newnode->next=crrptr;
            newnode->prev=NULL;
            crrptr->prev=newnode;
            return newnode;
        }
        else
        {
            crrptr->prev->next=newnode;
            newnode->prev=crrptr->prev;
            newnode->next=crrptr;
            crrptr->prev=newnode;
            return left;
        }
    }
}

node* insert_After(node* crrptr,int info)
{
    node* right = crrptr;
    crrptr = search(crrptr,info);

    if(crrptr==NULL)
    {
        printf("\nNode not found...!");
        return right;
    }
    else
    {
        node* newnode = getNode();

        if(crrptr->next==NULL)
        {
            crrptr->next=newnode;
            newnode->next=NULL;
            newnode->prev=crrptr;
            return newnode;
        }
        else
        {
            crrptr->next->prev=newnode;
            newnode->next=crrptr->next;
            crrptr->next=newnode;
            newnode->prev=crrptr;
            return right;
        }
    } 
}

int main()
{
    node* right=getNode();
    node* left=right;
    right = create(right,left);
    display_Forward(left);
    display_Backward(right);
    int info;
    // printf("\nEnter the node to delete : ");
    // scanf("%d",&info);
    // node* temp = delete_Any(left,info);
    // if(temp==NULL)
    // {
    //     right=NULL;
    //     left=NULL;
    // }
    // else if(temp->next==NULL)
    // {
    //     right=temp;
    // }
    // else if(temp->prev==NULL)
    // {
    //     left=temp;
    // }
    // else
    // {
    //     left=temp;
    // }
    // display_Forward(left);
    // display_Backward(right);
    // printf("\nEnter the info to insert before : ");
    // scanf("%d",&info);
    // left = insert_Before(left,info);
    // display_Forward(left);
    // display_Backward(right);
    printf("\nEnter the info to insert after : ");
    scanf("%d",&info);
    right = insert_After(right,info);
    display_Forward(left);
    display_Backward(right);
    return 0;
}