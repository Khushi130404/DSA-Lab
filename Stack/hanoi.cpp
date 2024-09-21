#include <stdio.h>
#include "stack2.cpp"



void hanoi (int n,stack<int> &s1,stack <int> &s2,stack<int> &s3)
{
    
    if(n!=0)
    {
        hanoi(n-1,s1,s3,s2);
        if(!s1.isempty())
        {
             s3.push(s1.peek());
            //printf("\n%d",s1.pop());
        
        }
        hanoi(n-1,s2,s1,s3);
    }   
}


int main()
{
    int n=3;
    stack <int> s1;
    stack <int> s2;
    stack <int> s3;
    // stack <int> *sp1;
    // sp1=&s1;
    // stack <int> *sp2;
    // sp2=&s2;
    // stack <int> *sp3;
    // sp3=&s3;

    
    s1.push(30);
    s1.push(20);
    s1.push(10);
    
   //printf("\n%d\n%d\n%d",s1.peek(),s1.peek(),s1.peek());
   //hanoi(n,sp1,sp2,sp3);
   //hanoi(n,s1,s2,s3);
   //printf("\n%d\n%d\n%d",(*sp1).pop(),(*sp1).pop(),(*sp1).pop());
    //printf("\n\n\n%d\n%d\n%d",s3.pop(),s3.pop(),s3.pop());
     printf("\nElements in s1:\n");
    // while (!s1.isempty()) {
    //     printf("%d\n", s1.peek());
    // }

    hanoi(n, s1, s2, s3);

    printf("\nElements in s3:\n");
    while (!s3.isempty()) {
        printf("%d\n", s3.pop());
    }
    return 0;
}
// #include <stdio.h>
// #include "stack2.cpp"


// void hanoi (int n,stack<int>&s1,stack<int>&s2,stack<int>&s3)
// {
//     if(n!=0){
//     hanoi(n-1,s1,s3,s2);
//     s3.push(s1.peek());
//     s1.pop();
//     hanoi(n-1,s2,s1,s3);
//     }
// }


// int main()
// {
//     int n=3;
//     stack <int> s1;
//     stack <int> s2;
//     stack <int> s3;
    
//     s1.push(30);
//     s1.push(20);
//     s1.push(10);
//     //printf("\n%d\n%d\n%d",s1.peek(),s1.peek(),s1.peek());
//    //hanoi(n,sp1,sp2,sp3);
//    hanoi(n,s1,s2,s3);
//    //printf("\n%d\n%d\n%d",(*sp1).pop(),(*sp1).pop(),(*sp1).pop());
//    for(int i=0; i<3; i++)
//    {
//         printf("\n%d",s3.peek());
//         s3.pop();
//    }
//     return 0;
// }