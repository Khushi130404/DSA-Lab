# include <stdio.h>
# include <stdlib.h>

struct BinarySearchTree
{
    int info;
    struct BinarySearchTree* left;
    struct BinarySearchTree* right;
};
typedef struct BinarySearchTree node;

node* getNode()
{
    node* newnode = (node*)malloc(sizeof(node));
    printf("\nEnter the info : ");
    scanf("%d",&newnode->info);
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node* createTree(node* root)
{
    node* newnode = getNode();
    node* crrptr = root;

    if(root==NULL)
    {
        root=newnode;
        return root;
    }
    else
    {
        while(crrptr!=NULL)
        {
            if(newnode->info>crrptr->info)
            {
                if(crrptr->right!=NULL)
                {
                    crrptr=crrptr->right;
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
                    crrptr=crrptr->left;
                }
                else
                {
                    break;
                }
            }
        }
        if(newnode->info>crrptr->info)
        {
            crrptr->right=newnode;
        }
        else
        {
            crrptr->left=newnode;
        }
        return root;
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

int main()
{
    int n;
    node* root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        root = createTree(root);
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