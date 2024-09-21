#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct node 
{
    int info;
    struct node *link;
};

void create(struct node*);
void show(struct node*);


int main()
{
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    create(head);
    show(head);

    return 0;
}

void create(struct node *head)
{
    struct node *newnode;
    char ans;
    while(1)
    {
        printf("\nEnter the info");
        scanf("%d",&head->info);
        printf("\nDo you want to continue?");
        fflush(stdin);
        scanf("%c",&ans);
        if(toupper(ans)=='Y')
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            head->link=newnode;
            head=newnode;
        }
        else
        {
            head->link=NULL;
            break;
        }

    }
}

void show(struct node* head)
{
    int c=0;
    while(head!=NULL)
    {
        printf("\n%d",head->info);
        head=head->link;
        c++;
    }
    printf("\nCount: %d",c);
}