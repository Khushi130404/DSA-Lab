# include <stdio.h>
# define max 3

int top[3]={0,0,0};

void push(int stack[],int disk)
{
    if(top[stack[0]]!=max)
    {
        top[stack[0]]++;
        stack[top[stack[0]]]=disk;
    }
}

int pop(int stack[])
{
    if(top[stack[0]]!=0)
    {
        return stack[top[stack[0]]--];
    }
}
void hanoi(int n,int st1[],int st2[], int st3[])
{
    if(n!=0)
    {
        hanoi(n-1,st1,st3,st2);
        push(st3,pop(st1));
        hanoi(n-1,st2,st1,st3);
    }
}

int main()
{
    int n=3;
    int stack1[max+1];
    int stack2[max+1];
    int stack3[max+1];

    stack1[0]=1;
    stack2[0]=2;
    stack3[0]=3;

    push(stack1,30);
    push(stack1,20);
    push(stack1,10);

    hanoi(n,stack1,stack2,stack3);

    printf("%d\n",pop(stack3));
    printf("%d\n",pop(stack3));
    printf("%d\n",pop(stack3));
    return 0;
}