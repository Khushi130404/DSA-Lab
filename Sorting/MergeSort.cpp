#include <stdio.h>

int n;
void Two_way_split(int [],int,int);
void Simple_merge(int [],int,int,int);

int main()
{
    printf("\nEnter the size of array: ");
    scanf("%d",&n);
    int arr[n];

    printf("\nEnter the elements of array...\n");
    for(int i=0; i<n; i++)
    {
        printf("Arr[%d]: ",i+1);
        scanf("%d",&arr[i]);
    }

    Two_way_split(arr,0,n-1);

    printf("\nDisplay of sorted array....");
    for(int i=0; i<n; i++)
    {
        printf("\nArr[%d]: %d",i+1,arr[i]);
    }
    return 0;
}

void Two_way_split(int arr[], int start, int finish)
{
    int size=finish-start+1;

    if(size!=1)
    {
        int middle = start+(size/2)-1;
        Two_way_split(arr,start,middle);
        Two_way_split(arr,middle+1,finish);
        Simple_merge(arr,start,middle+1,finish);
    }
}

void Simple_merge(int arr[],int first,int second,int third)
{
    int temp[n];
    int i=first,j=second,k=0;

    while(i<second && j<=third)
    {
        if(arr[i]<arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    if(i==second)
    {
        while(j<=third)
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<second)
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
    }

    for(int l=0; l<k; l++)
    {
        arr[first+l]=temp[l];
    }
}