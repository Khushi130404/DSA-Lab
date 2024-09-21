#include <stdio.h>

class queue
{
    int f=-1,r=-1;
    int a[5];
    public: 

    int isfull()
    {
        if(r==4 && f==0)
        {
            return 1;
        }
        else if(r==f-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    
    }
    int isempty()
    {
        if(r==-1 && f==-1)
        {
            return 1;
        }
        else if(r==f-1)
        {
            r=-1;
            f=-1;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void insert()
    {
        if(isfull())
        {
            printf("\nQueue is full\n");
        }
        else
        {
            if(r==-1 && f==-1)
            {
                r++;
                f++;
            }
            else if(r==4)
            {
                r=0;
            }
            else
            {
                r++;
            }
            printf("Enter the number: ");
            scanf("%d",&a[r]);
        }   
    }
    void delet()
    {
        if(isempty())
        {
            printf("\nQueue is empty\n");
        }
        else
        {

            if(f==4 && r==4)
            {
                f=-1;
                r=-1;
                printf("\n%d",a[4]);
            }
            if(f==4)
            {
                f=-1;
                printf("\n%d",a[4]);
            }
            else
            {
                f++;
                printf("\n%d",a[f-1]);
            }
        }
            
    }
    void peek()
    {
        if(!isempty())
        {
            printf("\n%d",a[r]);
        }
    }

};
int main()
{
    queue q;
    int n=0;
    while(n!=4)
    {
        printf("\nEnter 1 for insert\nEnter 2 for delete\nEnter 3 for peek\nEnter 4 for exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: q.insert();
                    break;
            case 2: q.delet();
                    break;
            case 3: q.peek();
                    break;
        }
    }
    return 0;
}