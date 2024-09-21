#include <stdio.h>

int Linear_search(int [],int);

int main()
{
    int n;
    printf("\nEnter the size of an array: ");
    scanf("%d",&n);
    int arr[n+1];

    printf("\nEnter the elements...\n");
    for(int i=0; i<n; i++)
    {
        printf("Array[%d]: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d",&arr[n]);

    int found = Linear_search(arr,n);
    if(found == -1)
    {
        printf("\nUnsuccessful Search...!");
    }
    else
    {
        printf("\nSuccessful search...!");
        printf("\nElement %d is at the index %d",arr[n],found+1);
    }
    return 0;
}

int Linear_search(int arr[],int n)
{
    int i=0;
    while(arr[i]!=arr[n])
    {
        i++;
    }
    if(i==n)
    {
        return -1;
    }
    else
    {
        return i;
    }

}