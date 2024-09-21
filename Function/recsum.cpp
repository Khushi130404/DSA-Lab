#include <stdio.h>
int sum(int);

int main()
{
    int n;
    printf("\nEnter the number: ");
    scanf("%d",&n);
    printf("\nSum: %d",sum(n));
    return 0;
}

int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return n+sum(n-1);
    }
}