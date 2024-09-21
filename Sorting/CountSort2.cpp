//Count Sorting

#include <stdio.h>

int main()
{
    int sum=0;
    int a[5]={7,19,28,5,13};
    int max=a[0],min=a[0];
    for(int i=0; i<5; i++)
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
    int c[5];
    int b[max-min+1][3]={0};
    for(int i=0; i<5; i++)
    {
        b[i][0]=a[i];
        b[i][1]=a[i]-i;
        
    }
    for(int i=0; i<=max-min; i++)
    {
        sum=sum+b[i][0];
        b[i][0]=sum;
    }
    // for(int i=4; i>=0; i--)
    // {
    //     c[b[a[i]]-1]=a[i];
    //     b[a[i]]--;
    // }
    for(int i=0; i<5; i++)
    {
        printf("\na[%d]= %d",i,c[i]);
    }
    return 0;
}