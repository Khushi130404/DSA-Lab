#include <stdio.h>

void create_heap(int [],int);
void heap_sort(int [],int);

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int heap[n];
    printf("\nEnter the elements...\n");
    for(int i=0; i<n; i++)
    {
        printf("Array[%d]: ",i+1);
        scanf("%d",&heap[i]);
    }
    create_heap(heap,n);
    heap_sort(heap,n);
    printf("\nSorted array...");
    for(int i=0; i<n; i++)
    {
        printf("\nArray[%d]: %d",i+1,heap[i]);
    }
    return 0;
}

void create_heap(int arr[],int n)
{
    int q = 1;
    int key,i,j;

    while(q<n)
    {
        i=q;
        key=arr[q];
        j=i/2;

        while(i>0 && key>arr[j])
        {
            arr[i]=arr[j];
            i=j;
            j=i/2;
        }
        arr[i]=key;
        q++;
    }
}

void heap_sort(int arr[],int n)
{
    create_heap(arr,n);
    int q=n-1;
    int i,key,j;

    while(q>0)
    {
        int temp = arr[q];
        arr[q] = arr[0];
        arr[0] = temp;

        i=0;
        key=arr[0];
        j=1;

        if(j+1 < q && arr[j+1]>arr[j])
        {
            j++;
        }
        
        while(j<q && key<arr[j])
        {
            arr[i]=arr[j];
            i=j;
            j=2*i+1;

            if(j+1 < q && arr[j+1]>arr[j])
            {
                j++;   
            }
            else if(j>n-1)
            {
                j=n-1;
            }
            arr[i]=key;
        }
    q--;
    }
}