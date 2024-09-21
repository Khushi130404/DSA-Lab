//Evaluation of a postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float stack[50];
int top=-1,i,len;
float final_result,n1,n2,value,result;
void push(float);
float pop();

int main()
{
    char postfix[50];
    printf("\nEnter the postfix expression: ");
    gets(postfix);
    len=strlen(postfix);
    for(int i=0; i<len; i++)
    {
        if(postfix[i]>= '0' && postfix[i]<='9')
        {
            push(postfix[i]-'0');
        }
        else if((postfix[i]>='a' && postfix[i]<='z')||(postfix[i]>='A' && postfix[i]<='Z'))
        {
            printf("\nEnter the value of variable %c: ",postfix[i]);
            scanf("%f",&value);
            push(value);
        }
        else
        {
            n1=pop();
            n2=pop();
            switch(postfix[i])
            {
                case '^':result = pow(n2,n1);
                        push(result);
                        break;
                case '+':result = n2+n1;
                        push(result);
                        break;
                case '-':result = n2-n1;
                        push(result);
                        break;
                case '*':result = n2*n1;
                        push(result);
                        break;
                case '/':result = n2/n1;
                        push(result);
                        break;
                default: printf("\nInvalid Operator....");
                        exit(0);
            }

        }
    }
    printf("\nSolution: %f",pop());
    return 0;
}
void push(float val)
{
    top++;
    stack[top]=val;
}
float pop()
{
    if(top==-1)
    {
        printf("\nInvalid postfix expression.....");
        exit(0);
    }
    else
    {
        top--;
        return stack[top+1];
    }
}