// Partition Exchange sort 

#include <stdio.h>
#include <stdlib.h>

int left,right,key;
int LB,UB;

void QuickSort(int [],int,int);

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int qs[n],i;
    for(int i=0; i<n; i++)
    {
        printf("arr[%d]: ",i+1);
        scanf("%d",&qs[i]);
    }
    LB=0;
    UB=n-1;

    QuickSort(qs,LB,UB);
    printf("\nSorted Array...");
    for(int i=0; i<n; i++)
    {
        printf("\narr[%d]: %d",i+1,qs[i]);
    }
    return 0;
}

void QuickSort(int qs[],int lb,int ub)
{
    int temp,key;
    if(lb<ub)
    {
        left=lb;
        right=ub+1;
        key=qs[lb];

        while(1)
        {
            left++;
            while(qs[left]<key)
            {
                left++;
            }
            right--;
            while(qs[right]>key)
            {
                right--;
            }
             if(right>left)
            {
                temp=qs[left];
                qs[left]=qs[right];
                qs[right]=temp;
            }
            else
            {
                break;
            }
        }
        qs[lb]=qs[right];
        qs[right]=key;

        QuickSort(qs,lb,right-1);
        QuickSort(qs,right+1,ub);
    }
}