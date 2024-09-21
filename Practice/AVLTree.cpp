#include <stdio.h>
#include <stdlib.h>

struct AVL_Tree_Node
{
    int key;
    struct AVL_Tree_Node* left;
    struct AVL_Tree_Node* right;
};
typedef struct AVL_Tree_Node node;

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

int height(node* crrptr)
{
    int h1,h2;

    if(crrptr==NULL)
    {
        return -1;
    }
    else if(crrptr->left==NULL && crrptr->right==NULL)
    {
        return 0;
    }
    else
    {
        if(crrptr->left!=NULL)
        {
            h1 = height(crrptr->left)+1;
        }
        if(crrptr->right!=NULL)
        {
            h2 = height(crrptr->right)+1;
        }
        return max(h1,h2);
    }
}

int balance_Factor(node* crrptr)
{
    return (height(crrptr->left)-height(crrptr->right));
}

node* left_Rotation(node* x)
{
    node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

node* right_Rotation(node* x)
{
    node* y = x->left;
    x->left = y->right;
    y->right = x;
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

    if(balance_Factor(crrptr)<-1)
    {
        if(balance_Factor(crrptr->right)<=0)
        {
            crrptr = left_Rotation(crrptr);
        }
        else
        {
            crrptr = right_left_Rotation(crrptr);
        }
    }
    else if(balance_Factor(crrptr)>1)
    {
        if(balance_Factor(crrptr->left)>=0)
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

node* insert(node* root)
{
    node* crrptr = root;
    node* newnode = getNode();

    if(root==NULL)
    {
        return newnode;
    }
    else
    {
        while (crrptr!=NULL)
        {
            if(newnode->key>crrptr->key)
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
        if(newnode->key>crrptr->key)
        {
            crrptr->right=newnode;
        }
        else
        {
            crrptr->left=newnode;
        }
        root = balance_Tree(root);
        return root;
    }
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

node* search(node* crrptr,int info)
{
    if(crrptr==NULL)
    {
        return crrptr;
    }
    else if(crrptr->key==info)
    {
        return crrptr;
    }    
    else if(crrptr->key<info && crrptr->right!=NULL)
    {
        return search(crrptr->right,info);
    }
    else if(crrptr->key>=info && crrptr->left!=NULL)
    {
        return search(crrptr->left,info);
    }
    else
    {
        return NULL;
    }
}

node* search_Parent(node* crrptr,int info)
{
    node* parent = NULL;
    while(crrptr!=NULL)
    {
        if(crrptr->key==info)
        {
            return parent;
        }
        else if(info>crrptr->key && crrptr->right!=NULL)
        {
            parent=crrptr;
            crrptr=crrptr->right;
        }
        else if(info<=crrptr->key && crrptr->left!=NULL)
        {
            parent=crrptr;
            crrptr=crrptr->left;
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
}

int InorderSuccesor(node* crrptr)
{
    node* parent=crrptr;
    crrptr=crrptr->right;
    if(crrptr->left==NULL)
    {
        parent->right=crrptr->right;
        return crrptr->key;
    }

    while(crrptr->left!=NULL)
    {
        parent=crrptr;
        crrptr=crrptr->left;
    }
    parent->left=NULL;
    return crrptr->key;    
}

int InorderPredeccessor(node* crrptr)
{
    node* parent=crrptr;
    crrptr=crrptr->left;
    if(crrptr->right==NULL)
    {
        parent->left=crrptr->left;
        return crrptr->key;
    }

    while(crrptr->right!=NULL)
    {
        parent=crrptr;
        crrptr=crrptr->right;
    }
    parent->right=NULL;
    return crrptr->key;    
}

node* deleteNode(node* root)
{
    int info;
    printf("\nEnter the info to delete: ");
    scanf("%d",&info);
    node* del = search(root,info);
    node* parent = search_Parent(root,info);

    if(del==NULL)
    {
        printf("\nNode not found...!");
        return root;
    }
    else
    {
        printf("\nNode found...!");
        if(del->left==NULL && del->right==NULL)
        {
            if(parent->left==del)
            {
                parent->left=NULL;
            }
            else
            {
                parent->right=NULL;
            }
        }
        else
        {
            if(balance_Factor>=0)
            {
                parent->key = InorderPredeccessor(parent);
            }
            else
            {
                parent->key = InorderSuccesor(parent);
            }

        }
        root = balance_Tree(root);
        return root;
    }

}

int main()
{
    int n;
    node* root = NULL;

    // Insertion of node
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        root = insert(root);
    }
    printf("\nBinary Search Tree traversal...\n");
    printf("Pre-Order traversal...\n");
    PreOrder(root);
    printf("\nPost-Order traversal...\n");
    PostOrder(root);
    printf("\nIn-Order traversal...\n");
    InOrder(root);

    root = deleteNode(root);
    printf("\nBinary Search Tree traversal...\n");
    printf("Pre-Order traversal...\n");
    PreOrder(root);
    printf("\nPost-Order traversal...\n");
    PostOrder(root);
    printf("\nIn-Order traversal...\n");
    InOrder(root);

    return 0;
}