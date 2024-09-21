# include <stdio.h>


int findMax(int arr[],int n)
{
    int max = arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}

int maxPass(int max)
{
    int r=0;
    while(max!=0)
    {
        max=max/10;
        r++;
    }
    return r;
}

void radixSort(int arr[],int n)
{
    int pass = maxPass(findMax(arr,n));
    int bucket_pass[10][n];
    int r,divisor=1;

    for(int ps=0; ps<pass; ps++)
    {
        int bucket[10]={0};
        for(int i=0; i<n; i++)
        {
            r=(arr[i]/divisor)%10;
            bucket_pass[r][bucket[r]]=arr[i];
            bucket[r]++;
        }
        int k=0;
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<bucket[i] ;j++)
            {
                arr[k] = bucket_pass[i][j];
                k++;
            }
        }
        divisor*=10;
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

    radixSort(arr,size);

    printf("\n\nSorted array...");
    for(int i=0; i<size; i++)
    {
        printf("\narr[%d] = %d",i+1,arr[i]);
    }

    return 0;
}