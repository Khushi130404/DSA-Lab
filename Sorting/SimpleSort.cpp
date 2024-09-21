//Simple Sorting

#include <stdio.h>

int main()
{
    int a[10];
    for(int i=0; i<10; i++)
    {
        printf("Enter the number: ");
        scanf("%d",&a[i]);
    }
    for(int i=0; i<10; i++)
    {
        for(int j=i; j<10; j++)
        {
            if(a[i]>a[j])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=0; i<10; i++)
    {
        printf("\na[%d]= %d",i,a[i]);
    }
    return 0;
}