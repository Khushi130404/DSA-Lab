// Write a C program to reverse a string using stack

#include <stdio.h>

void reverse ();

int main()
{
    printf("\nEnter the string: ");
    reverse();
    return 0;
}

void reverse()
{
    char c;
    if((c=getchar())!= '\n')
    {
        reverse();
    }
    putchar(c);
}