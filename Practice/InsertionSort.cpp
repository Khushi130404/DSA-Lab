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

    for(int i=0 ; i<size; i++)
    {
        int key=arr[i];
        int j;
        for(j=i-1; j>=0; j--)
        {
            if(key<arr[j])
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1]=key;
    }

    printf("\n\nSorted array...");
    for(int i=0; i<size; i++)
    {
        printf("\narr[%d] = %d",i+1,arr[i]);
    }

    return 0;
}