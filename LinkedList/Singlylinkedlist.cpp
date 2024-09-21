//Singly Linked List

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //Header file to convert upper to lower or lower to upper

struct node 
{
    int info;
    struct node *link;
};typedef struct node node; //To assign nickname to data type

void Display(node*);
void Create_link_list(node*);
int Count(node*);
int largest(node*);
node* Insert_first(node*);
node* Getnode();
void Insert_last(node*);
node* Search(node*,int);
void Insert_after(node*);
node* Delete_first(node*);
void Delete_last(node*);
node* Delete_any(node*);
node* Insert_before(node*);
node* Rev_link_list(node*);
node* copy_link_list(node*);
node* get_malloc();
node* concate(node*,node*);

int main()
{
    node *head,*temp;
    int item;
    node* head2;
    head=(node*)malloc(sizeof(node));
    Create_link_list(head);
    Display(head);
    printf("\nCount: %d",Count(head));
    printf("\nLargest info: %d",largest(head));
    printf("\nDisplay operation after insertion: ");
    head=Insert_first(head);
    Display(head);
    node *crrptr=head;
    Insert_last(head);
    Display(head);
    printf("\nSearch Operation: ");
    printf("\nEnter node info to search: ");
    scanf("%d",&item);
    temp = Search(head,item);
    if(temp==NULL)
    {
        printf("\nNode not found");
    }
    else
    {
        printf("\nNode Found");
    }
    printf("\nInserting an element after item");
    Insert_after(head);
    Display(head);
    printf("\n\nDelete first node ");
    head = Delete_first(head);
    Display(head);
    printf("\nDeleting Last element");
    Delete_last(head);
    Display(head);
    printf("\nDelete any info");
    head=Delete_any(head);
    Display(head);
    printf("\nBefor Insertion");
    head = Insert_before(head);
    Display(head);
    printf("\nReverse the linked list");
    head=Rev_link_list(head);
    Display(head);
    // printf("\nCopying the link list\n");
    // head2=copy_link_list(head);
    // Display(head2);
    // printf("\nConcate two linked list\n");
    // head=concate(head,head2);
    // Display(head);
    return 0;
}

void Display(node* crrptr)
{
    while(crrptr!=NULL)
    {
        printf("\n%d",crrptr->info);
        crrptr=crrptr->link;
    }

}
void Create_link_list(node* crrptr)
{
    node *newnode;
    char ans;
    while(1)
    {
        printf("\nEnter the info: ");
        scanf("%d",&crrptr->info);
        fflush(stdin);
        printf("\nDo you want to continue? ");
        scanf("%c",&ans);
        if(toupper(ans)=='Y')
        {
            newnode=(node*)malloc(sizeof(node));
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
int Count (node* crrptr)
{
    int c=0;
    while(crrptr!=NULL)
    {
        c++;
        crrptr=crrptr->link;
    }
    return c;
}
int largest (node* crrptr)
{
    int max=crrptr->info;
    crrptr=crrptr->link;
    while(crrptr!=NULL)
    {
        if(max<crrptr->info)
        {
            max=crrptr->info;
        }
        crrptr=crrptr->link;
    }
    return max;
}
node* Insert_first(node* crrptr)
{
    node* newnode;
    newnode = Getnode();
    newnode->link=crrptr;
    return newnode;
}
node* Getnode()
{
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the number : ");
    scanf("%d",&newnode->info);
    return newnode;
}
void Insert_last(node *crrptr)
{
    node *newnode=Getnode();
    newnode->link=NULL;
    while(crrptr->link!=NULL)
    {   
        crrptr=crrptr->link;
    }
    crrptr->link=newnode;   
}
node* Search(node* crrptr,int item)
{
    while(crrptr!=NULL)
    {
        if(crrptr->info==item)
        {
            return crrptr;  //Node Found
        }
        crrptr=crrptr->link;
    }
    return NULL;  //Node not found
    //return crrptr
}
void Insert_after(node* crrptr)
{
    node* location;
    node *newnode;
    int search_item;
    printf("\nEnter the info after which you want to insert a node");
    scanf("%d",&search_item);
    location = Search(crrptr,search_item);
    if(location == NULL)
    {
        printf("\nSearch item not found\nInsertion not possible");
    }
    else
    {   
    
        newnode=Getnode();
        newnode->link=location->link;
        location->link=newnode;
    }
}
node* Delete_first(node* crrptr)
{
    // crrptr = crrptr->link;
    // return crrptr;
    
    //return crrptr->link;

    node* temp;
    temp=crrptr;
    crrptr = crrptr->link;
    free(temp);
    return crrptr;
}
void Delete_last(node* crrptr)
{
    while(crrptr->link->link!=NULL)
    {
        crrptr=crrptr->link;
    }
    crrptr->link=NULL;
}
node* Delete_any (node* crrptr)
{
    node* first;
    first=crrptr;
    if(crrptr!=NULL)
    {
    node* location;
    int item,flage=0;
    printf("\nEnter the number to delete: ");
    scanf("%d",&item);
    if(crrptr->info==item)
    {
        flage=1;
        crrptr=crrptr->link;
        first=crrptr;
    }
    else
    {
        while(crrptr->link!=NULL)
        {
            if(crrptr->link->info==item)
            {
                crrptr->link=crrptr->link->link;
                flage=1;
                break;
            }
            crrptr=crrptr->link;   
        }
    }
    if(flage==0)
    {
        printf("\nNode not found");
    }
    }
    return first;
}
node* Insert_before(node * crrptr)
{
    node* newnode;
    node* temp;
    temp=crrptr;
    int item,flage=0;
    printf("\nEnter the info: ");
    scanf("%d",&item);
    if(temp->info==item)
    {
        flage=1;
        newnode=Getnode();
        newnode->link=crrptr;
        return newnode;
    }
    while(crrptr->link->info!=item && crrptr->link!=NULL)
    {
        crrptr=crrptr->link;
    }
    if(crrptr->link!=NULL)
    {
        flage=1;
       newnode=Getnode();
       newnode->link=crrptr->link;
       crrptr->link=newnode;
    }
   if(flage==0)
   {
        printf("\nNode not found");
        return temp;
   }
    return temp;
}
node* Rev_link_list(node* crrptr)
{
    node* nxptr;
    node* first;
    first=NULL;
    while(crrptr!=NULL)
    {
        nxptr=crrptr->link;
        crrptr->link=first;
        first=crrptr;
        crrptr=nxptr;

    }
    return first;
}
node* get_malloc()
{
    node* newnode;
    newnode=(node*)malloc(sizeof(node*));
    return newnode;
}
node* copy_link_list(node* crrptr)
{
    node* head=NULL;
    node* newnode;
    node* node;
    while(crrptr!=NULL)
    {
        if(head==NULL)
        {
            head=get_malloc();
            head->info=crrptr->info;
            head->link=NULL;
            node=head;
        }
        else
        {
            newnode=get_malloc();
            newnode->info=crrptr->info;
            node->link=newnode;
            node=newnode;
        }
        crrptr=crrptr->link;
    }
    return head;
}
node* concate(node* crrptr1,node* crrptr2)
{
    node* temp=crrptr1;
    while(crrptr1->link!=NULL)
    {
        crrptr1=crrptr1->link;
    }
    crrptr1->link=crrptr2;
    return temp;
}