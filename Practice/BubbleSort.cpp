# include <stdio.h>

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

    for(int i=0 ; i<size; i++)
    {
        exch=0;
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                exch++;
            }
        }
        if(exch==0)
        {
            break;
        }
    }

    printf("\n\nSorted array...");
    for(int i=0; i<size; i++)
    {
        printf("\narr[%d] = %d",i+1,arr[i]);
    }

    return 0;
}