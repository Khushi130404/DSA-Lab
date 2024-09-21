#include <stdio.h>
#include <stdlib.h>

struct Tree_node
{
    int info;
    struct Tree_node *left;
    struct Tree_node *right;
};typedef struct Tree_node node;

node* getNode();
node* Create_node(node*);
void PreOrder(node*);
void PostOrder(node*);
void InOrder(node*);

int main()
{ 
    int ele,i,n;
    node *root;
    printf("\nLet's create binay tree....!");
    root=Create_node(root);
    printf("\nPre-Order display...\n");
    PreOrder(root);
    printf("\nPost-Order display...\n");
    PostOrder(root);
    printf("\nIn-Order display...\n");
    InOrder(root);
    return 0;
}

node* getNode()
{
    node* newnode;
    int info;
    printf("\nEnter the info for the node: ");
    fflush(stdin);
    scanf("%d",&info);
    if(info==-1)
    {
        newnode=NULL;
    }
    else
    {
        newnode=(node*)malloc(sizeof(node));
        newnode->info=info;
        newnode->left=NULL;
        newnode->right=NULL;
    }
    return newnode;
}
node* Create_node(node* crrptr)
{
    node* newnode=getNode();
    crrptr=newnode;
    if(crrptr==NULL)
    {
        return crrptr;
    }
    printf("\nFor LEFT of %d node ",crrptr->info);
    crrptr->left=Create_node(crrptr->left);
    printf("\nFor RIGHT of %d node ",crrptr->info);
    crrptr->right=Create_node(crrptr->right);
    return crrptr;
}
void PreOrder(node* crrptr)
{
    if(crrptr!=NULL)
    {
        printf("\t%d",crrptr->info);
        PreOrder(crrptr->left);
        PreOrder(crrptr->right);
    }
}

void PostOrder(node* crrptr)
{
    if(crrptr!=NULL)
    {
        PostOrder(crrptr->left);
        PostOrder(crrptr->right);
        printf("\t%d",crrptr->info);
    }
}

void InOrder(node* crrptr)
{
    if(crrptr!=NULL)
    {
        InOrder(crrptr->left);
        printf("\t%d",crrptr->info);      
        InOrder(crrptr->right);
    }
}