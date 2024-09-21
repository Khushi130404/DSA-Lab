// Write a 'C' program for inserting a node,
//postorder traversal,
//counting total number of nodes for binary search tree

# include <stdio.h>
#include <stdlib.h>

struct Binary_Search_Tree_node
{
    int info;
    struct Binary_Search_Tree_node *left;
    struct Binary_Search_Tree_node *right;
};
typedef struct Binary_Search_Tree_node node;

node* root;

node* getnode();
void Create();
void PreOrder(node*);
void InOrder(node*);
void PostOrder(node*);

int main()
{
    int n;
    root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        Create();
    }
    printf("\nBinary Search Tree traversal...\n");
    printf("Pre-Order traversal...\n");
    PreOrder(root);
    printf("\nIn-Order traversal...\n");
    InOrder(root);
    printf("\nPost-Order traversal...\n");
    PostOrder(root);
    return 0;
}

node* getnode()
{
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("Enter the node info: ");
    scanf("%d",&newnode->info);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void Create()
{
    node* newnode = getnode();
    node* crrptr=root;

    if(root==NULL)
    {
        root = newnode;
    }
    else
    {
        while(crrptr!=NULL)
        {
            if(newnode->info > crrptr->info)
            {
                if(crrptr->right!=NULL)
                {
                    crrptr = crrptr->right;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(crrptr->left!=NULL)
                {
                    crrptr = crrptr->left;
                }
                else
                {
                    break;
                }
            }
        }

        if(crrptr->info < newnode->info)
        {
            crrptr->right = newnode;
        }
        else
        {
            crrptr->left = newnode;
        }
    }
}
void PreOrder(node* crrptr)
{
    if(crrptr!=NULL)
    {
        printf("%d\t",crrptr->info);        
        PreOrder(crrptr->left);
        PreOrder(crrptr->right);
    }
}
void InOrder(node* crrptr)
{
    if(crrptr!=NULL)
    {
        InOrder(crrptr->left);
        printf("%d\t",crrptr->info);
        InOrder(crrptr->right);
    }
}
void PostOrder(node* crrptr)
{
    if(crrptr!=NULL)
    {
        PostOrder(crrptr->left);
        PostOrder(crrptr->right);
        printf("%d\t",crrptr->info);
    }
}
