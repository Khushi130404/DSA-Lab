#include <stdio.h>

int add(int ,int);
int sub(int,int);
int mult(int,int);
int div(int,int);

int main()
{
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);

    printf("The addition of %d and %d is %d\n",a,b,add(a,b));
    printf("The subtraction of %d and %d is %d\n",a,b,sub(a,b));
    printf("The multiplication of %d and %d is %d\n",a,b,mult(a,b));
    if(b!=0)
    {
        printf("The divition of %d and %d is %d\n",a,b,div(a,b));
    }
    
    return 0;
}

int add(int x,int y)
{
    return x+y;
}
int sub(int x,int y)
{
    return x-y;
}
int mult(int x ,int y)
{
    return x*y;
}
int div(int x,int y)
{
    return x/y;
}
