// Bubble Sort Amit sir
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
    for(int i=0; i<n; i++)
    {
        exchg=0;
        for(int j=0; j<n-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                exchg++;
            } //end of if
        } //end of for j
        if(exchg==0)
        {
            break;
        }
    } //end of for i

    for(int i=0; i<n; i++) //display loop
    {
        printf("\narr[%d]: %d",i+1,arr[i]);
    }
    
    return 0;
}