#include <stdio.h>
#include <stdlib.h>

//node is a tage name
struct node 
{
    //structure member variable
    int info;  
    struct node *Link;
};
int main()
{
    struct node *node1,*node2,*node3; //structure variable
    node1=(struct node*)malloc(sizeof(struct node));
    node2=(struct node*)malloc(sizeof(struct node));
    node3=(struct node*)malloc(sizeof(struct node));
    node1->info=10;
    //(*node1).info=10;
    node1->Link=node2;
    node2->info=20;
    node2->Link=node3;
    node3->info=30;
    node3->Link=NULL;
    printf("%d\n%d\n%d",node1->info,node2->info,node3->info);
    printf("\n%d\n%d\n%d",node1->info,node1->Link->info,node1->Link->Link->info);

    return 0;
}