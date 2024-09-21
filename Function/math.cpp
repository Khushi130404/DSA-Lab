#include <stdio.h>

int main()
{
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);

    printf("The addition of %d and %d is %d\n",a,b,a+b);
    printf("The subtraction of %d and %d is %d\n",a,b,a-b);
    printf("The multiplication of %d and %d is %d\n",a,b,a*b);
    if(b!=0)
    {
        printf("The divition of %d and %d is %d\n",a,b,a/b);
    }
    
    return 0;
}