//Count Sorting

#include <stdio.h>

int main()
{
    int sum=0;
    int a[10];
    for(int i=0; i<10; i++)
    {
        printf("Enter the number: ");
        scanf("%d",&a[i]);
    }
    int max=a[0],min=a[0];
    for(int i=0; i<10; i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
        if(min>a[i])
        {
            min=a[i];
        }
    }
    int c[10];
    int b[max-min+1]={0};
    for(int i=0; i<10; i++)
    {
        b[a[i]-min]++;
    }
    for(int i=0; i<=max-min; i++)
    {
        sum=sum+b[i];
        b[i]=sum;
    }
    for(int i=9; i>=0; i--)
    {
        c[b[a[i]-min]-1]=a[i];
        b[a[i]-min]--;
    }
    for(int i=0; i<10; i++)
    {
        printf("\na[%d]= %d",i,c[i]);
    }
    return 0;
}