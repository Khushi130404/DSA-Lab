# include <stdio.h>
# include <math.h>
# include <string.h>
# define size 50

float stack[size];
int top=-1;

void push(float num)
{
    top++;
    stack[top]=num;
}

float pop()
{
    return stack[top--];
}

float evaluate(float a,float b,char c)
{
    switch (c)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '^': return pow(a,b);
    }
}

float PostfixEvaluation(char postfix[30])
{
    for(int i=0; i<strlen(postfix); i++)
    {
        if(postfix[i]>='0' && postfix[i]<='9')
        {
            push(postfix[i]-'0');
        }
        else if((postfix[i]>='a' && postfix[i]<='z') || (postfix[i]>='A' && postfix[i]<='Z'))
        {
            float temp;
            printf("Enter the value of %c : ",postfix[i]);
            scanf("%f",&temp);
            push(temp);
        }
        else
        {
            float b = pop();
            float a = pop();
            push(evaluate(a,b,postfix[i]));
        }
    }
    return pop();
}

int main()
{
    char postfix[30];
    printf("\nEnter the expression : ");
    gets(postfix);
    printf("\nAns : %f",PostfixEvaluation(postfix));
    return 0;
}

