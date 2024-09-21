#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 4

struct B_Plus_Tree_Node
{
    int keys[MAX_KEYS];
    struct B_Plus_Tree_Node* children[MAX_KEYS + 1];
    int num_keys;
    int is_leaf;
    struct B_Plus_Tree_Node* next;
};
typedef struct B_Plus_Tree_Node node;

node* createnode(int);
void insert(node**, int);
void inorderTraversal(node*);

int main() 
{
    node* root = createnode(1);

    int num_keys;
    printf("Enter the number of keys to insert: ");
    scanf("%d", &num_keys);

    printf("Enter the keys to insert:\n");
    for (int i = 0; i < num_keys; i++) 
    {
        int key;
        scanf("%d", &key);
        insert(&root, key);
    }

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}

node* createnode(int is_leaf) 
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->num_keys = 0;
    newnode->is_leaf = is_leaf;
    newnode->next = NULL;
    for (int i = 0; i < MAX_KEYS + 1; i++) 
    {
        newnode->children[i] = NULL;
    }
    return newnode;
}

// Insertion function for a B+ tree
void insert(node** root, int key) 
{
    node* rootnode = *root;

    if (rootnode->is_leaf) 
    {
        // Leaf node insertion
        int i = rootnode->num_keys - 1;

        while (i >= 0 && key < rootnode->keys[i]) 
        {
            rootnode->keys[i + 1] = rootnode->keys[i];
            i--;
        }
        rootnode->keys[i + 1] = key;
        rootnode->num_keys++;

        // Update the linked list
        if (rootnode->next != NULL) 
        {
            rootnode->next->keys[0] = key;
        }
    } 
    else 
    {
        // Internal node insertion
        int i = 0;
        while (i < rootnode->num_keys && key > rootnode->keys[i]) 
        {
            i++;
        }
        insert(&rootnode->children[i], key);
    }

    // Split the root if it's full
    if (rootnode->num_keys == MAX_KEYS) 
    {
        node* newRoot = createnode(0);
        newRoot->children[0] = rootnode;
        *root = newRoot;
    }
}

void inorderTraversal(node* node) 
{
    if (node) 
    {
        int i;
        for (i = 0; i < node->num_keys; i++) 
        {
            inorderTraversal(node->children[i]);
            printf("%d ", node->keys[i]);
        }
        inorderTraversal(node->children[i]);
    }
}
