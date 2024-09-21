#include <stdio.h>
static int steps = 0;
void hanoi(int,char,char,char);

int main()
{
    int n;
    printf("\nEnter the numnber of disks: ");
    scanf("%d",&n);
    hanoi(n,'a','b','c');
    printf("\nSteps: %d",steps);
    return 0;
}

void hanoi(int n,char sn,char in,char dn)
{
    if(n!=0)
    {
        hanoi(n-1,sn,dn,in);
        printf("\nMove disk %d from %c to %c",n,sn,dn);
        steps++;
        hanoi(n-1,in,sn,dn);
    }   
}