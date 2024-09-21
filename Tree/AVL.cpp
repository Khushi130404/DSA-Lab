// Inplementation of AVL tree

#include <stdio.h>
#include <stdlib.h>

struct AVL_Tree_Node
{
    int key;
    struct AVL_Tree_Node* left;
    struct AVL_Tree_Node* right;
};
typedef struct AVL_Tree_Node node;

node* getNode();
int height(node*);
int max(int,int);
int balance_factor(node*);
node* right_Rotation(node*);
node* left_Rotation(node*);
node* left_right_Rotation(node*);
node* right_left_Rotation(node*);
node* Insert_node(node*);
node* balance_Tree(node*);
void PreOrder(node*);
void InOrder(node*);
void PostOrder(node*);
node* search_node(node*,int);
node* search_before_node(node*,int);
node* delete_node(node*);
int Inorder_successor(node*);
int Inorder_predeccessor(node*);

int main()
{
    int n;
    node* root = NULL;

    // Insertion of node
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        root = Insert_node(root);
    }
    printf("\nBinary Search Tree traversal...\n");
    printf("Pre-Order traversal...\n");
    PreOrder(root);
    printf("\nPost-Order traversal...\n");
    PostOrder(root);
    printf("\nIn-Order traversal...\n");
    InOrder(root);

    // Search operation
    int search;
    node* searchNode;
    printf("\nEnter the node to search: ");
    scanf("%d",&search);
    searchNode = search_node(root,search);
    if(searchNode==NULL)
    {
        printf("\nNode not found...!");
    }
    else
    {
        printf("\nNode found...!\n%d",searchNode->key);
    }

    // Deletion operation
    root = delete_node(root);
    printf("\nBinary Search Tree traversal...\n");
    printf("Pre-Order traversal...\n");
    PreOrder(root);
    printf("\nPost-Order traversal...\n");
    PostOrder(root);
    printf("\nIn-Order traversal...\n");
    InOrder(root);

    return 0;
}

node* getNode()
{
    node* newnode = (node*) malloc(sizeof(node));
    printf("\nEnter the info for node: ");
    scanf("%d",&newnode->key);
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
int max (int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int height (node* crrptr)
{
    int height1=0,height2=0;
    if(crrptr==NULL)
    {
        return -1;
    }
    else if(crrptr->left == NULL && crrptr->right==NULL)
    {
        return 0;
    }
    else
    {
        if(crrptr->left!=NULL)
        {
            height1 = height(crrptr->left)+1;
        }
        if(crrptr->right!=NULL)
        {
            height2 = height(crrptr->right)+1; 
        }
        return max(height1,height2);
    }
}
int balance_factor(node* crrptr)
{
    return (height(crrptr->left)-height(crrptr->right));
}
node* right_Rotation(node* x)
{
    node* y = x->left;
    node* z = y->left;

    x->left = y->right;
    y->right = x;
    return y;
}
node* left_Rotation(node* x)
{
    node* y = x->right;
    node* z = y->right;

    x->right = y->left;
    y->left = x;
    return y;
}
node* left_right_Rotation(node* x)
{
    x->left = left_Rotation(x->left);
    x = right_Rotation(x);
    return x;
}
node* right_left_Rotation(node* x)
{
    x->right = right_Rotation(x->right);
    x = left_Rotation(x);
    return x;
}
node* Insert_node(node* root)
{
    node* newnode = getNode();
    node* crrptr = root;

    if(crrptr==NULL)
    {
        root = newnode;
    }
    else
    {
        while(crrptr!=NULL)
        {
            if(newnode->key > crrptr->key)
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
        if(newnode->key > crrptr->key)
        {
            crrptr->right = newnode;
        }
        else
        {
            crrptr->left = newnode;
        }
        root = balance_Tree(root);
    }
    return root;
}
node* balance_Tree(node* crrptr)
{
    if(crrptr==NULL)
    {
        return crrptr;
    }
    if(crrptr->left!=NULL)
    {
        crrptr->left = balance_Tree(crrptr->left);
    }
    if(crrptr->right!=NULL)
    {
        crrptr->right = balance_Tree(crrptr->right);
    }
    
    if(balance_factor(crrptr) < -1)
    {
        if(balance_factor(crrptr->right)<=0)
        {
            crrptr = left_Rotation(crrptr);
        }
        else
        {
            crrptr = right_left_Rotation(crrptr);
        }
    }
    else if(balance_factor(crrptr)>1)
    {
        if(balance_factor(crrptr->left)>=0)
        {
            crrptr = right_Rotation(crrptr);
        }
        else
        {
            crrptr = left_right_Rotation(crrptr);
        }
    }    
    return crrptr;
}
void PreOrder(node* crrptr)
{
    if(crrptr!=NULL)
    {
        printf("%d\t",crrptr->key);        
        PreOrder(crrptr->left);
        PreOrder(crrptr->right);
    }
}
void InOrder(node* crrptr)
{
    if(crrptr!=NULL)
    {
        InOrder(crrptr->left);
        printf("%d\t",crrptr->key);
        InOrder(crrptr->right);
    }
}
void PostOrder(node* crrptr)
{
    if(crrptr!=NULL)
    {
        PostOrder(crrptr->left);
        PostOrder(crrptr->right);
        printf("%d\t",crrptr->key);
    }
}
node* search_node(node* crrptr,int info)
{ 
    node* search = NULL;
    if(crrptr==NULL)
    {
        return NULL;
    }
    else if(crrptr->key==info)
    {
        return crrptr;   
    }
    else if(crrptr->key > info)
    {
        return search_node(crrptr->left,info);
    }
    else
    {
        return search_node(crrptr->right,info);
    }
}
node* search_before_node(node* crrptr,int info)
{
    node* parent = NULL;
    while(crrptr!=NULL)
    {
        if(crrptr->key == info)
        {
            return parent;
        }
        else if(crrptr->left!=NULL && crrptr->key > info)
        {
            parent = crrptr;
            crrptr = crrptr->left;
        }
        else if(crrptr->right!=NULL && crrptr->key < info)
        {
            parent = crrptr;
            crrptr = crrptr->right;
        }
        else
        {
            return NULL;
        }
    }  
    return NULL;  
}
int  Inorder_successor(node* crrptr)
{
    node* parent = crrptr;
    crrptr = crrptr->right;
    if(crrptr->left==NULL)
    {
        parent->right = crrptr->right;
        return crrptr->key;
    }
    while(crrptr->left!=NULL)
    {
        parent = crrptr;
        crrptr = crrptr->left;
    }
    parent->left = NULL;
    return crrptr->key;
}
int Inorder_predeccessor(node* crrptr)
{
    node* parent = crrptr;
    crrptr = crrptr->left;
    if(crrptr->right==NULL)
    {
        parent->left = crrptr->left;
        return crrptr->key;
    }
    while(crrptr->right!=NULL)
    {
        parent = crrptr;
        crrptr = crrptr->right;
    }
    parent->right=NULL;
    return crrptr->key;
}
node* delete_node(node* root)
{
    int info;
    printf("\nEnter the info to delete: ");
    scanf("%d",&info);
    node* search = search_node(root,info);
    node* parent = search_before_node(root,info);
    if(search == NULL)
    {
        printf("\nNode not found...!");
    }
    else if(search->left==NULL && search->right==NULL)
    {
        printf("\nNode found...!");
        if(parent->left == search)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }
    else
    {
        printf("\nNode found...!");
        if(balance_factor(search)>=0)
        {
            search->key = Inorder_predeccessor(search);
        }
        else
        {
            search->key = Inorder_successor(search);
        }
    }
    root = balance_Tree(root);
    return root;
}