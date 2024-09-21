#include <stdio.h>

int main()
{
    int flage=0;
    int n;
    printf("Enter size of arry: ");
    scanf("%d",&n);
    int a[n];

    for(int i=0; i<n; i++)
    {
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    printf("Enter the number to be found: ");
    int find;
    scanf("%d",&find);
        
    for(int i=0; i<n; i++)
    {
        if(a[i]==find)
        {
            printf("\nIndex: %d",i);
            flage=1;
        }
    } 
    if(flage==0)
    {
        printf("\nNo element found ");
    } 
    return 0;
}