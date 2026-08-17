// Write a program to print strings in reverse order using stack.

#include<stdio.h>
#define MAX 4

int stack[MAX],top=-1;
void pop();

void main()
{
    string op;
    do
    {
        print("\n pop");

         printf("\n Enter a string :");
         scanf("%d",&op);

          switch(op)
        {
            case 1:
                pop();
                break;
        }

    } while(op!=5);
}

    void pop()

{
    string val;
    if(top==-1)
    {
       printf("\n stack underflow..");

    }
    else
    {
        val=stack[top];
        top--;
       printf("\n Value deleted is : %d",val);

    }

}







