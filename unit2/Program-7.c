/*Write a program to find the Smallest Common Divisor of a given
number.*/


#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value);
int pop();

void main()
 {
    int a, div,i;

    printf("Enter value A: ");
    scanf("%d", &a);

    for (i=2;i<=a;i++)
    {
        if(a%i==0)
        {
            push(i);
        }
    }

    for (i=2;i<=a;i++)
    {
        if(a%i==0)
        {
             div=pop();
        }
    }

    printf("The Smallest common divisor is %d", div);
}

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("\nStack overflow.\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

int pop()
 {
    if (top == -1)
    {
        printf("\nStack underflow.\n");
        return -1;
    }

    else

    {
        int v = stack[top];
        top--;
        return v;
    }
}
