# include <stdio.h>

int main()
{
    int size;
    printf("\nEnter the size of array : ");
    scanf("%d",&size);
    int a[size];
    int c[size];
    int exch=0;
    printf("\nEnter the elements of array...\n");
    for(int i=0; i<size; i++)
    {
        printf("arr[%d] = ",i+1);
        scanf("%d",&a[i]);
    }

    int max=a[0],min=a[0];
    for(int i=1; i<size; i++)
    {   
        if(a[i]>max)
        {
            max=a[i];
        }
        if(a[i]<min)
        {
            min=a[i];
        }
    }

    int b[max-min+1]={0};

    for(int i=0; i<size; i++)
    {
        b[a[i]-min]++;
    }
    for(int i=1; i<=max-min; i++)
    {
        b[i]+=b[i-1];
    }
    for(int i=size-1; i>=0; i--)
    {
        c[b[a[i]-min]-1]=a[i];
        b[a[i]-min]--;
    }

    printf("\n\nSorted array...");
    for(int i=0; i<size; i++)
    {
        printf("\narr[%d] = %d",i+1,c[i]);
    }

    return 0;
}