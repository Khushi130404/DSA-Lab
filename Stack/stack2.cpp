
#include <stdio.h>
#define size 5
static int st=-1;
template <class T>
class stack
{
    T a[size];
    public:
    int isempty()
    {
        if(st==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isfull()
    {
        if(st==size-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    
    }
    

    void push(T b)
    {
        if(!isfull())
        {
            st++;  
            a[st]=b;
        }

    }
    int peek()
    {
        if(!isempty())
        {
          return a[st];  
        }
    }

    int pop()
    {
        if(!isempty())
        {
           return a[st--]; 
        }
    }
};

// #include <stdio.h>
// #include <stdbool.h>

// #define SIZE 3
// int stack[SIZE];
// int top = -1;

// bool isEmpty() {
//     return top == -1;
// }

// bool isFull() {
//     return top == SIZE - 1;
// }

// void push(int item) {
//     if (!isFull()) {
//         stack[++top] = item;
//     } else {
//         printf("Stack is full. Cannot push element.\n");
//     }
// }

// int peek() {
//     if (!isEmpty()) {
//         return stack[top];
//     } else {
//         printf("Stack is empty. Cannot peek.\n");
//         // You may return a default value or handle the error as needed.
//     }
// }

// int pop() {
//     if (!isEmpty()) {
//         return stack[top--];
//     } else {
//         printf("Stack is empty. Cannot pop.\n");
//         // You may return a default value or handle the error as needed.
//     }
// }

// int main() {
//     push(1);
//     push(2);
//     push(3);

//     printf("Top of the stack: %d\n", peek());

//     while (!isEmpty()) {
//         printf("Popped: %d\n", pop());
//     }

//     return 0;
// }
