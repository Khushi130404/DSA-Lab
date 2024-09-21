#include <stdio.h>

void swap(int*,int*);

int main()
{
    int a=4,b=7;
    // int *p,*q;
    // p=&a;
    // q=&b;
    printf("\na=%d\nb=%d",a,b);
    swap(&a,&b);
    printf("\na=%d\nb=%d",a,b);
    return 0;
}

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}