# include <stdio.h>
# include <sys/time.h>
# include <random>

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
    struct timeval v1,v2;
    struct timezone z1,z2;
    printf("\nEnter the size of array : ");
    scanf("%d",&size);
    int arr[size];
    printf("\nEnter the elements of array...\n");
    // for(int i=0; i<size; i++)
    // {
    //     arr[i]=rand();
    //     printf("arr[%d] = %d\n",i+1,arr[i]);
    // }

    gettimeofday(&v1,&z1);
    radixSort(arr,size);
    gettimeofday(&v2,&z2);

    printf("\n\nSorted array...");
    // for(int i=0; i<size; i++)
    // {
    //     printf("\narr[%d] = %d",i+1,arr[i]);
    // }
    
    printf("\n\nTime Difference : %ld",(v2.tv_usec-v1.tv_usec));
    return 0;
}