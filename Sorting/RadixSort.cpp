// Radix Sort
// Bucket Sort
// Nor comparision based algorithm
// Stable sort

# include <stdio.h>

int find_max(int [],int);
int number_Of_Passes(int);
void radix_Sort(int [],int);

int main()
{
    int size;
    printf("\nEnter the size of array:  ");
    scanf("%d",&size);
    int radix[size];
    printf("\nEnter the elements...\n");
    for(int i=0; i<size; i++)
    {
        printf("Array[%d]: ",i+1);
        scanf("%d",&radix[i]);
    }
    radix_Sort(radix,size);
    printf("\nSorted array...");
    for(int i=0; i<size; i++)
    {
        printf("\nArray[%d]: %d",i+1,radix[i]);        
    }
    return 0;
} 

int find_max(int arr[],int size)
{
    int max = arr[0];

    for(int i=1; i<size; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}

int number_Of_Passes(int n)
{
    int pass=0;
    while(n>0)
    {
        pass++;
        n = n/10;
    }
    return pass;
}

void radix_Sort(int arr[], int size)
{
    int pass = number_Of_Passes(find_max(arr,size));
    int bucket[10][size];
    int r,divisor=1;

    for(int ps=0; ps<pass; ps++)
    {
        int bucket_count[10]={0};
        for(int i=0; i<size; i++)
        {
            r=(arr[i]/divisor)%10;
            bucket[r][bucket_count[r]] = arr[i];
            bucket_count[r]++;
        }

        int i=0;
        for(int j=0; j<10; j++)
        {
            for(int k=0; k<bucket_count[j]; k++)
            {
                arr[i] = bucket[j][k];
                i++;
            }
        }

        printf("After pass %d...\n",(ps+1));
        for(int j=0; j<size; j++)
        {
            printf("Array[%d]: %d\n",j+1,arr[j]);
        }
        divisor=divisor*10;
    }
}

