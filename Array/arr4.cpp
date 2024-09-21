#include <stdio.h>

// Write a program to delete an element in an array.

int main()
{
    int n;
    printf("Enter size of arry: ");
    scanf("%d",&n);
    int a[n];

    for(int i=0; i<n; i++)
    {
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    printf("Enter the position to be delete: ");
    int index;
    scanf("%d",&index);

        
    for(int i=index; i<n; i++)
    {
       a[i-1]=a[i];
    } 
    for(int i=0; i<n-1; i++)
    {
        printf("\na[%d]: %d ",i,a[i]);
    }
    return 0;
}