# include <stdio.h>
# include <stdlib.h>

struct BinaryTree
{
    int info;
    struct BinaryTree* left;
    struct BinaryTree* right;
};
typedef struct BinaryTree node;

node* getNode()
{
    int info;
    node* newnode;
    printf("\nEnter the value : ");
    scanf("%d",&info);
    if(info==-1)
    {
        return NULL;
    }
    else
    {
        newnode = (node*)malloc(sizeof(node));
        newnode->info=info;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
}

node* createTree(node* crrptr)
{
    crrptr = getNode();
    if(crrptr==NULL)
    {
        return NULL;
    }
    printf("\nFor the left of %d node...",crrptr->info);
    crrptr->left = createTree(crrptr->left);
    printf("\nFor the right of %d node...",crrptr->info);
    crrptr->right = createTree(crrptr->right);
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

void InOrder(node* crrptr)
{
    if(crrptr!=NULL)
    {
        InOrder(crrptr->left);
        printf("\t%d",crrptr->info);
        InOrder(crrptr->right);
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


int main()
{
    int ele,i,n;
    node *root;
    printf("\nLet's create binay tree....!");
    root=createTree(root);
    printf("\nPre-Order display...\n");
    PreOrder(root);
    printf("\nPost-Order display...\n");
    PostOrder(root);
    printf("\nIn-Order display...\n");
    InOrder(root);
    return 0;
}