#include <stdio.h>

void split(int [],int [],int [],int);
void sort(int [],int,int);
void merge(int [],int [],int []);

int main()
{
    int a[10]={7,4,3,2,8,1,5,9,6,0};
    sort(a,0,9);
    for(int i=0; i<10; i++)
    {
        printf("\na[%d]: %d",i,a[i]);
    }
    printf("Size: %d",sizeof(a)/sizeof(a[0]));
    return 0;
}

void split(int a[],int b[],int c[],int down)
{
    for(int i=0,j=0; i<sizeof(a)/sizeof(a[0]); i++)
    {
        if(i<down)
        {
            b[i]=a[i];
        }
        else if(i>down)
        {
            c[j]=a[i];
            j++;
        }
    }
}
void merge(int a[],int b[],int c[])
{
    for(int i=0,j=0; i<sizeof(a)/sizeof(a[0]); i++)
    {
        if(i<sizeof(b)/sizeof(b[0]))
        {   
            a[i]=b[i];
        }
        else if(i<sizeof(b)/sizeof(b[0]))
        {
            a[i]=c[j];
            j++;
        }
    }
}
void sort(int a[],int up,int down)
{
    int key=a[up-1];
    int size=sizeof(a)/sizeof(a[0]);
    while(up<down)
    {
        while(key>a[up])
        {
            up++;
        }
        while(key<a[down])
        {
            down--;
        }
        if(up<down)
        {
            int t = a[down];
            a[down]=a[up];
            a[up]=t;
        }
    }
    if(key==a[down])
    {
        a[down]=key;
    }
    else
    {
        int t = key;
        key=a[down];
        a[down]=key;
        int b[down];
        int c[size-down];
        split(a,b,c,down);
        sort(b,1,down-1);
        sort(c,down+1,size-1);
        merge(a,b,c);
        a[down]=key;
    }
}