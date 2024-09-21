// Insertion Sort Amit sir
#include <stdio.h>

int main()
{
    int n;
    int exchg;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++) //Input loop
    {
        printf("\nInfo of arr[%d]: ",i+1);
        scanf("%d",&arr[i]);
    }
    
    for(int pass=1; pass<n; pass++)
    {
        for(int i=pass; i>0; i--)
        {
            if(arr[i]<arr[i-1])
            {
                int temp = arr[i];
                arr[i]=arr[i-1];
                arr[i-1]=temp;
            }
            else
            {
                break;
            }
        }
    }
    

    for(int i=0; i<n; i++) //display loop
    {
        printf("\narr[%d]: %d",i+1,arr[i]);
    }
    
    return 0;
}