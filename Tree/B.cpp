#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 3

struct B_Tree_Node
{
    int keys[MAX_KEYS];
    struct B_Tree_Node* children[MAX_KEYS + 1];
    int num_keys;
    int is_leaf;
};typedef struct B_Tree_Node node;

node* createNode(int);
void splitChild(node*, int);
void insertNonFull(node*, int);
void insert(node**, int);
void inorderTraversal(node*);
node* search(node*, int);

int main() 
{
    node* root = createNode(1);

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

    int searchKey;
    printf("Enter a key to search: ");
    scanf("%d", &searchKey);

    node* result = search(root, searchKey);
    if (result) 
    {
        printf("Key %d found in the tree.\n", searchKey);
    } 
    else 
    {
        printf("Key %d not found in the tree.\n", searchKey);
    }

    return 0;
}

node* createNode(int is_leaf)
 {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->num_keys = 0;
    newnode->is_leaf = is_leaf;

    for (int i = 0; i < MAX_KEYS + 1; i++)
    {
        newnode->children[i] = NULL;
    }
    return newnode;
}

void splitChild(node* parent, int index)
{
    node* child = parent->children[index];
    node* newChild = createNode(child->is_leaf);
    parent->num_keys++;

    for (int i = parent->num_keys - 1; i > index; i--)
    {
        parent->keys[i] = parent->keys[i - 1];
        parent->children[i + 1] = parent->children[i];
    }

    parent->keys[index] = child->keys[MAX_KEYS / 2];
    parent->children[index + 1] = newChild;

    for (int i = 0; i < MAX_KEYS / 2; i++) 
    {
        newChild->keys[i] = child->keys[i + (MAX_KEYS / 2) + 1];
        child->keys[i + (MAX_KEYS / 2) + 1] = 0;
    }

    if (!child->is_leaf) 
    {
        for (int i = 0; i < MAX_KEYS / 2 + 1; i++) 
        {
            newChild->children[i] = child->children[i + (MAX_KEYS / 2) + 1];
            child->children[i + (MAX_KEYS / 2) + 1] = NULL;
        }
    }

    child->num_keys = MAX_KEYS / 2;
    newChild->num_keys = MAX_KEYS / 2;
}

void insertNonFull(node* node, int key) 
{
    int i = node->num_keys - 1;

    if (node->is_leaf) 
    {
        while (i >= 0 && key < node->keys[i]) 
        {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->num_keys++;
    } 
    else 
    {
        while (i >= 0 && key < node->keys[i]) 
        {
            i--;
        }
        i++;
        if (node->children[i]->num_keys == MAX_KEYS) 
        {
            splitChild(node, i);
            if (key > node->keys[i]) 
            {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

void insert(node** root, int key) 
{
    node* rootnode = *root;

    if (rootnode->num_keys == MAX_KEYS) 
    {
        node* newRoot = createNode(0);
        newRoot->children[0] = rootnode;
        *root = newRoot;
        splitChild(newRoot, 0);
        insertNonFull(newRoot, key);
    } 
    else 
    {
        insertNonFull(rootnode, key);
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

node* search(node* node, int key) 
{
    int i = 0;

    while (i < node->num_keys && key > node->keys[i]) 
    {
        i++;
    }

    if (i < node->num_keys && key == node->keys[i]) 
    {
        return node;
    } 
    else if (node->is_leaf) 
    {
        return NULL;
    }
    else 
    {
        return search(node->children[i], key);
    }
}
