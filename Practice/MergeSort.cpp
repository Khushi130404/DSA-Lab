# include <stdio.h>
# include <stdlib.h>

void merge(int arr[],int first,int second,int third)
{
    int temp[third-first+1];
    int i=first,j=second,k=0;

    while(i<second && j<=third)
    {
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            i++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i==second)
    {
        while(j<=third)
        {
            temp[k]=arr[j];
            k++;
            j++;
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
    for(int l=0; l<=third-first; l++)
    {
        arr[first+l]=temp[l];
    }
}

void split(int arr[],int start,int finish)
{
    if(finish>start)
    {
        int middle = (start+finish+1)/2;
        split(arr,start,middle-1);
        split(arr,middle,finish);
        merge(arr,start,middle,finish);
    }
}

int main()
{
    int size;
    printf("\nEnter the size of array : ");
    scanf("%d",&size);
    int arr[size];
    int exch=0;
    printf("\nEnter the elements of array...\n");
    for(int i=0; i<size; i++)
    {
        printf("arr[%d] = ",i+1);
        scanf("%d",&arr[i]);
    }

    split(arr,0,size-1);

    printf("\n\nSorted array...");
    for(int i=0; i<size; i++)
    {
        printf("\narr[%d] = %d",i+1,arr[i]);
    }
    return 0;
}