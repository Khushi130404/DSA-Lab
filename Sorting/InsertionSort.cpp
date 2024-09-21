//Insertion Sorting

#include <stdio.h>
 
int main()
{
    int a[10];
    int key,j;
    for(int i=0; i<10; i++)
    {
        printf("Enter the number: ");
        scanf("%d",&a[i]);
    }
    for(int i=1; i<10; i++)
    {
        key=a[i];
        for(j = i-1; j>=0; j--)
        {
            if(key<a[j])
            {
                a[j+1]=a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1]=key;
    }
    for(int i=0; i<10; i++)
    {
        printf("\na[%d]= %d",i,a[i]);
    }
    return 0;
}