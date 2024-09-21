#include <stdio.h>

// Write a program to insert an element in an array.

int main()
{
    int n;
    printf("Enter size of arry: ");
    scanf("%d",&n);
    int a[n+1];

    for(int i=0; i<n; i++)
    {
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    printf("Enter the number to insert and its position: ");
    int insert;
    int index;
    scanf("%d %d",&insert,&index);
    int c=index-1;
        
    for(int i=n; i>c; i--)
    {
       a[i+1]=a[i];
    } 
    a[c]=insert;
    for(int i=0; i<n+1; i++)
    {
        printf("\na[%d]: %d ",i,a[i]);
    }
    return 0;
}