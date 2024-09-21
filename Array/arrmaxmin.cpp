#include <stdio.h>

int main()
{
    int sum=0;
    int a[5];
    int b[5];
    for(int i=0; i<5; i++)
    {
        printf("a[%d]: ",i);
        scanf("%d",&a[i]); 
    }
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
        printf("\na[%d]: %d",i,a[i]);
    }
    printf("\n\nMAX: %d\n\nMIN: %d",max,min); 
}