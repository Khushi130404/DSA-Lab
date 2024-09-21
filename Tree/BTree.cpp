// Implementation of B Tree
// Dynamic Multi-level index

#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define MIN 2

struct B_Tree_Node
{
    int info[MAX];
    struct B_Tree_Node* link[MAX];
    struct B_Tree_Node* parent;
    int size;
};
typedef B_Tree_Node node;

node* getNode(int);
int Is_BTree_Full(node*);
node* find_leaf(node*,int);
void sort_node(node*);
int Insert_Info(int,node*);
node* Split_node(node*);


int main()
{
    return 0;
}

node* getNode()
{
    node* newnode = (node*) malloc(sizeof(node));
    newnode->parent = NULL;
    newnode->size = 0;
    for(int i=0; i<MAX-1; i++)
    {
        newnode->info[i]=-1;
        newnode->link[i] = NULL;
    }
    return newnode;
}
int Is_BTree_Full(node* crrptr)
{
    if(crrptr->size==MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
node* find_leaf(node* crrptr,int key)
{
    if(crrptr->link[0]==NULL)
    {
        for(int i=0; i<MAX; i++)
        {
            // if(key==crrptr->info[i])
            // {
            //     return NULL;
            // }
        }
        return crrptr;
    }
    else
    {
        for(int i=0; i<MAX; i++)
        {
            if(crrptr->info[i]>=key)
            {
                return find_leaf(crrptr->link[i],key);
            }
            if(crrptr->info[i]==-1)
            {
                return find_leaf(crrptr->link[i-1],key);
            }
        }
        return find_leaf(crrptr->link[MAX-1],key);
    }
}
void sort_node(node* crrptr)
{
    node* temp;
    int info;

    for(int i=0; i<crrptr->size; i++)
    {
        for(int j=0; j<crrptr->size; j++)
        {
            if(crrptr->info[i]<crrptr->info[j])
            {
                info = crrptr->info[i];
                temp = crrptr->link[i];

                crrptr->info[i] = crrptr->info[j];
                crrptr->link[i] = crrptr->link[j];

                crrptr->info[j] = info;
                crrptr->link[j] = temp;
            }
        }
    }
}
node* Split_node(node* crrptr)
{
    if(crrptr->parent==NULL)
    {
        int index = (int)crrptr->size/2;
        node* temp = getNode();
        node* root = getNode();
        int i,j;
        root->info[0] = crrptr->info[index];
        root->size++;
        crrptr->info[index] = -1;

        for(i=index+1,j=0; i<crrptr->size; i++,j++)
        {
            temp->info[j] = crrptr->info[i];
            crrptr->info[i] = -1;
            temp->link[j] = crrptr->link[i];
            crrptr->link[i]=NULL;
            crrptr->size--;
            temp->size++;
        }
        
        temp->link[j] = crrptr->link[crrptr->size];
        root->link[0] = crrptr;
        root->link[1] = temp;
        crrptr->parent = root;
        temp->parent = root;
        return root;
    }
}
// int Insert_Info(int info,node* crrptr)
// {
//     if(crrptr->size<MAX)
//     {
//         int i;
//         for(i=0; i<crrptr->size; i++)
//         {
//             if(crrptr->info[i]>info)
//             {
//                 break;
//             }
//         }
//         for(int j=crrptr->size; j>=i ; j--)
//         {
//             crrptr->info[j+1] = crrptr->info[j];
//         }
//         crrptr->info[i]=info;
//         crrptr->size++;
//         return i;
//     }
// }
// node* Split_node(node* crrptr,node* parent)
// {
//     int mediun = crrptr->info[crrptr->size/2];
//     int index = crrptr->size/2;
    
//     node* newnode = getNode(crrptr->info[index+1]);
//     for(int i=index+1; i<crrptr->size; i++)
//     {
//         Insert_Info(crrptr->info[i],newnode);
//         crrptr->size--;
//     }

//     index = Insert_Info(mediun,parent);
//     crrptr->size--;
//     parent->link[index]=crrptr;
//     parent->link[index+1]=newnode;
// }

