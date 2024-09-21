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
    
    for(int i=0; i<5; i++)
    {
        printf("\na[%d]: %d",i,a[i]);
    }  
}