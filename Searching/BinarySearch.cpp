#include <stdio.h>

int Binary_search(int [],int,int);

int main()
{
    int n,find;
    printf("\nEnter the size of an array: ");
    scanf("%d",&n);
    int arr[n];

    printf("\nEnter the elements...\n");
    for(int i=0; i<n; i++)
    {
        printf("Array[%d]: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d",&find);

    int found = Binary_search(arr,find,n);
    
    if(found==-1)
    {
        printf("\nUnsuccessful search...!");
    }
    else
    {
        printf("\nSuccessful search...!");
        printf("\nIndex of %d : %d",find,found);
    }
    return 0;
}

int Binary_search(int arr[],int find,int n)
{
    int low=0 ,high=n-1 ,middle;
    
    while(low <= high)
    {
        middle=(high+low)/2;
        if(find < arr[middle])
        {
            high = middle-1;
        }
        else if(find > arr[middle])
        {
            low = middle+1;
        }
        else
        {
            return middle+1;
        }
    }
    return -1;
}