 /*Write a program to find the factorial of a given integer number using
stack*/

#include<stdio.h>
#define MAX 20

int Stack [MAX],top=-1;
void push(int ch);
int pop();

void main()
{
    int i=0,n,fact=-1;
    printf("\nEnter value : ");
    scanf("%d",&n);

    for(i=0;i<=n;i++)
    {
        push(i);
    }
    while(top!=-1)
    {
        fact=fact*pop();
    }
    printf("\nFactorial is : %d",fact);
}

void push(int value)
{
    if(top==MAX-1)
    {
        printf("\n stack overflow..");
    }
    else
    {
        top++;
        Stack[top]=value;
    }
}

int pop()
{
    int val;
    if(top==-1)
    {
        printf("\n Stack is underflow..");
        return -1;
    }
    else
    {
        val=Stack[top];
        top--;
        return val;
    }
}



