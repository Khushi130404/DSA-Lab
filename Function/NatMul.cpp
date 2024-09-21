//Write a psuedocode in'c' language to find the multiplication of two numbers
#include <stdio.h>

int multi (int,int);
int Product(int,int);
int main()
{
    int a,b;
    printf("\nEnter the numbers to multiply: ");
    scanf("%d %d",&a,&b);
    printf("\nMultiplicatin: %d",multi(a,b));
    printf("\nMultiplication: %d",Product(a,b));
    return 0;
}

int multi (int a,int b)
{
    if(b==0)
    {
        return 0;
    }
    else
    {
        return a+multi(a,b-1);
    }
}

int Product(int a,int b)
{
    if(a<b)
    {
        return Product(b,a);
    }
    else if(b!=0)
    {
        return a+Product(a,b-1);
    }
    
    
        return 0;
    
    
}