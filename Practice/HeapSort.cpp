# include <stdio.h>

void createHeap(int arr[],int n)
{
    int q=1;
    int key,i,j;

    while(q<n)
    {
        i=q;
        key=arr[i];
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

void HeapSort(int arr[],int n)
{
    createHeap(arr,n);
    int i,j,key,q=n-1;

    while(q>0)
    {
        int temp=arr[0];
        arr[0]=arr[q];
        arr[q]=temp;

        i=0;
        key=arr[0];
        j=1;

        while(j+1<q && arr[j+1]>arr[j])
        {
            j++;
        }

        while(j<q && key<arr[j])
        {
            arr[i]=arr[j];
            i=j;
            j=2*i+1;

            if(j+1<q && arr[j+1]>arr[j])
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

int main()
{
    int arr[] = {4,9,6,1,-3};
    HeapSort(arr,5);
    for(int i=0; i<5; i++)
    {
        printf("\n%d",arr[i]);
    }
    return 0;
}