// Doubly Linked List

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* prev;
    struct node* next;
};typedef struct node node;

node* Getnode();
void Display_forward(node*);
void Display_backward(node*);
node* Insert_first(node*);
node* Insert_last(node*);
node* Search(node*,int);
node* Insert_before(node*);
node* Delete_first(node*);
node* Delete_last(node*);
node* Delete_any(node*);

int main()
{   
    node* newnode;
    char ans;
    int item;
    node* left=NULL;
    node* right=NULL;
    
     while(1)
    {
        printf("\nDo you want to continue? ");
        fflush(stdin);
        scanf("%c",&ans);
       
        if(toupper(ans)=='Y')
        {
            newnode=Getnode();
            if(right==NULL)
            {
                left=newnode;
                right=newnode;
            }
            else
            {
                right->next=newnode;
                newnode->prev=right;
                right=newnode;
            }  
        
        }
        else
        {
            break;
        }   //End of else
    }   //End of while
    
    printf("\nPrinting from forwrd");
    Display_forward(left);
    printf("\nPrinting from backward");
    Display_backward(right);
    printf("\nBefore Insertion");
    left=Insert_first(left);
    printf("\nForward display\n");
    Display_forward(left);
    printf("\nBackward display\n");
    Display_backward(right);
    printf("\nInsertion in last");
    right=Insert_last(right);
    printf("\nForward display\n");
    Display_forward(left);
    printf("\nBackward display\n");
    Display_backward(right);
    printf("\nEnter the number to search: ");
    scanf("%d",&item);
    newnode=Search(right,item);
    if(newnode!=NULL)
    {
        printf("\nNode found");
    }
    else
    {
        printf("\nNode not found");
    }
    printf("\nBefore Insertion");
    left=Insert_before(right);
    printf("\nPrinting from forwrd");
    Display_forward(left);
    printf("\nPrinting from backward");
    Display_backward(right);
    printf("\nDelete first");
    left=Delete_first(left);
    printf("\nPrinting from forwrd");
    Display_forward(left);
    printf("\nPrinting from backward");
    Display_backward(right);
    printf("\nDelete last");
    right=Delete_last(right);
    printf("\nPrinting from forwrd");
    Display_forward(left);
    printf("\nPrinting from backward");
    Display_backward(right);
    printf("\nDelete any");
    node* mynode;
    mynode=Delete_any(right);
    if(mynode==NULL)    //Empty link list
    {
        left=NULL;
        right=NULL;
    }
    else if(mynode->prev==NULL)
    {
        left=mynode;
    }
    else if(mynode->next==NULL)
    {
        right=mynode;
    }
    else
    {
        right=mynode;
    }
    printf("\nPrinting from forwrd");
    Display_forward(left);
    printf("\nPrinting from backward");
    Display_backward(right);

    return 0;

}

node* Getnode()
{
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter info: ");
    scanf("%d",&newnode->info);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void Display_forward(node* crrptr)
{
    while(crrptr!=NULL)
    {
        printf("\n%d",crrptr->info);
        crrptr=crrptr->next;
    }
}
void Display_backward(node* crrptr)
{
    while(crrptr!=NULL)
    {
        printf("\n%d",crrptr->info);
        crrptr=crrptr->prev;
    }
} 
node* Insert_first(node* crrptr)
{
    node* newnode;
    newnode=Getnode();
    newnode->next=crrptr;
    crrptr->prev=newnode;
    crrptr=newnode;
    return crrptr;
}
node* Insert_last(node* crrptr)
{
    node* newnode=Getnode();
    crrptr->next=newnode;
    newnode->prev=crrptr;
    crrptr=newnode;
    return crrptr;
}
node* Search(node* crrptr,int item)
{
    while(crrptr!=NULL)
    {
        if(crrptr->info!=item)
        {
            crrptr=crrptr->prev;
        }
        else
        {
            break;
        }
    }
    return crrptr;  
}
node* Insert_before(node* crrptr)
{
    int item;
    node* first;
    node* newnode;
    printf("\nEnter the info to search: ");
    fflush(stdin);
    scanf("%d",&item);
    node* node=Search(crrptr,item);
    if(node!=NULL)
    {
        newnode=Getnode();
        if(node->prev!=NULL)
        {
            //newnode->prev=node->prev;
            newnode->next=node;
            //node->prev=newnode;
            node->prev->next=newnode;
            newnode->prev=node->prev;
            node->prev=newnode;
            while(crrptr->prev!=NULL)
            {
                crrptr=crrptr->prev;
            }
            first=crrptr;
        }
        else
        {
            newnode->next=node;
            node->prev=newnode;
            node=newnode;
            first=node;
        }

    }
    else
    {
        while(crrptr->prev!=NULL)
        {
            crrptr=crrptr->prev;
        }
        first=crrptr;
        printf("\nNode not found");
    }
    return first;
}
node* Delete_first(node* crrptr)
{   
    node* temp;
    temp=crrptr;
    if(crrptr->next==NULL)
    {
        crrptr=NULL;
        free(temp);
    }
    else
    {
        crrptr=crrptr->next;
        temp->next=NULL;
        crrptr->prev=NULL;
        free(temp);
    }
    return crrptr;
}
node* Delete_last(node* crrptr)
{
    node* temp=crrptr;
    if(crrptr->prev==NULL)
    {
        free(temp);
        crrptr=NULL;
    }
    else
    {
        crrptr=crrptr->prev;
        temp->prev=NULL;
        crrptr->next=NULL;
        free(temp);
    }
    return crrptr;
}
node* Delete_any(node* crrptr)
{
    node* temp;
    node* first=crrptr;
    int item;
    printf("\nEnter the info to delete");
    scanf("%d",&item);
    crrptr=Search(crrptr,item);
    if(crrptr==NULL)
    {
        printf("\nNode not found");
    }
    else
    {
        if(crrptr->next==NULL && crrptr->prev==NULL) //When there is only one node
        {
            temp=crrptr;
            first=NULL;
            free(temp);
        }
        else if(crrptr->prev==NULL)
        {
            temp=crrptr;
            crrptr=crrptr->next;
            temp->next=NULL;
            crrptr->prev=NULL;
            free(temp);
            first=crrptr;
        }
        else if(crrptr->next==NULL)
        {
            temp=crrptr;
            crrptr=crrptr->prev;
            temp->prev=NULL;
            crrptr->next=NULL;
            free(temp);
            first=crrptr;
        }
        else
        {
            temp=crrptr;
            crrptr=crrptr->prev;
            crrptr->next=temp->next;
            temp->next->prev=crrptr;
            temp->next=NULL;
            temp->prev=NULL;
            free(temp);
        }
    }
    return first;
}
