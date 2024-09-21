#include "stdio.h"
#include "math3.cpp"

int main()
{
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);

    printf("The addition of %d and %d is %d\n",a,b,add(a,b));
    
    
    return 0;
}