#include<stdio.h>
#define MAX 20

int Stack [MAX],top=-1;
void push(int  ch);
int pop();

void main()
{
    int i=0,n,fact=-1;
    printf("\n Enter value : ");
    scanf("%d",&n);

    for(i=0;i<=n;i++)
    {
        push(i);
    }
    while(top!=-1)
    {
        printf("\n%c",pop());
    }
}

void push(char value)
{
    if(top==MAX-1)
    {
        printf("\n sack overflow..");
    }
    else
    {
        top++;
        Stack[top]=value;
    }
}

char pop()
{
    char val;
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



