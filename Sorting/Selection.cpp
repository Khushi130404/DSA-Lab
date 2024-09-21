// Write a program for selection sort
#include <stdio.h>

int main()
{
    int n,pass=0,i;
    int exchg,min_index,temp;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0; i<n; i++) //Input loop
    {
        printf("\nInfo of arr[%d]: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(pass=0; pass<n-1; pass++)
    {
        min_index = pass;
        for(i=pass+1; i<n; i++)
        {
            if(arr[i]<arr[min_index])
            {
                min_index=i;
            }
        }
        if(min_index!=pass)
        {
            temp=arr[pass];
            arr[pass]=arr[min_index];
            arr[min_index]=temp;
        }
    }
    for(i=0; i<n; i++) //display loop
    {
        printf("\narr[%d]: %d",i+1,arr[i]);
    }
    
    return 0;
}