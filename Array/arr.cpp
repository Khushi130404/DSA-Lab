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
        b[4-i]=a[i];
        sum=sum+a[i];
    }
    printf("\nNormal display: \n");
    for(int i=0; i<5; i++)
    {
        printf("\na[%d]: %d",i,a[i]);
    }
    printf("\n\nReverse DIsplay: \n");
    for(int i=0; i<5; i++)
    {
        printf("\nb[%d]: %d",i,b[i]);
    }
    printf("\n\nSum: %d",sum);
    
}