#include <stdio.h>

void Create_array(int [],int);
void Display_array(int [],int);
void Radix_sort(int [],int [],int);

int main()
{
    int n;
    printf("\nEnter the size of array: ");
    scanf("%d",&n);
    int radix[n];
    int d[n];
    Create_array(radix,n);
    for(int i=0; i<n; i++)
    {
        d[i]=radix[i];
    }
    Radix_sort(radix,d,n);
    Display_array(radix,n);
    return 0;
}

void Create_array(int arr[],int n)
{
    printf("\nEnter the elements of array...");
    for(int i=0; i<n; i++)
    {
        printf("\nRadix[%d]: ",i+1);
        scanf("%d",&arr[i]);
    }
}
void Radix_sort(int arr[],int d[],int n)
{
    int sum=0;
    int flag=0;
    int c[n];
    int a[10]={0};
    int b[n];
    for(int i=0; i<n; i++)
    {
        c[i]=d[i]%10;
        a[c[i]]++;
    }
    for(int i=0; i<10; i++)
    {
        sum+=a[i];
        a[i]=sum;
    }
    for(int i=n-1; i>=0; i--)
    {
        b[a[c[i]]-1] = arr[i];
        a[c[i]]--;
    }

    for(int i=0; i<n; i++)
    {
        // if(b[i]>=0 && b[i]<=9)
        // {
        //     return;
        // }
        d[i]=b[i];
        d[i]=(d[i]-(d[i]%10))/10;
        arr[i] = b[i];
        if(d[i]==0)
        {
            flag++;
            //return;
        }
        printf("\n%d",b[i]);    
    }
    if(flag==n-1)
    {
        return;
    }

    Radix_sort(arr,d,n);    
    // for(int i=0; i<n; i++)
    // {
    //     printf("%d",b[i]);
    //     arr[i] = b[i];
    // }
}


void Display_array(int arr[],int n)
{
    printf("\nSorted array...");
    for(int i=0; i<n; i++)
    {
        printf("\nRadix[%d]: %d",i+1,arr[i]);
    }
}