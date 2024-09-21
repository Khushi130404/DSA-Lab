#include <stdio.h>

long fact(long);

int main()
{
    long n;
    printf("\nEnter the number: ");
    scanf("%ld",&n);
    printf("\nFactorial: %d",fact(n));
    return 0;
}

long fact(long n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}