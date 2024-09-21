# include <stdio.h>
# include <random>
# include <sys/time.h>

void quickSort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int key=arr[lb];
        int left=lb;
        int right=ub+1;

        while(1)
        {
            left++;
            while(key>arr[left])
            {
                left++;
            }
            right--;
            while(key<arr[right])
            {
                right--;
            }
            if(left<right)
            {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
            else
            {
                break;
            }
        }
        arr[lb]=arr[right];
        arr[right]=key;

        quickSort(arr,lb,right-1);
        quickSort(arr,right+1,ub);
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
    int exch=0;
    printf("\nEnter the elements of array...\n");
    for(int i=0; i<size; i++)
    {
        arr[i] = rand();
        printf("arr[%d] = %d\n",i+1,arr[i]);
    }

    gettimeofday(&v1,&z1);
    quickSort(arr,0,size-1);
    gettimeofday(&v2,&z2);

    printf("\n\nSorted array...");
    for(int i=0; i<size; i++)
    {
        printf("\narr[%d] = %d",i+1,arr[i]);
    }

    printf("\n\nTime Difference : %ld",(v2.tv_usec-v1.tv_usec));

    return 0;
}