# include <stdio.h>

int main()
{
    int size;
    printf("\nEnter the size of array : ");
    scanf("%d",&size);
    int arr[size];
    printf("\nEnter the elements of array...\n");
    for(int i=0; i<size; i++)
    {
        printf("arr[%d] = ",i+1);
        scanf("%d",&arr[i]);
    }

    for(int i=0; i<size-1; i++)
    {
        for(int j=i; j<size; j++)
        {
            if(arr[i]>arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\n\nSorted array...");
    for(int i=0; i<size; i++)
    {
        printf("\narr[%d] = %d",i+1,arr[i]);
    }

    return 0;
}