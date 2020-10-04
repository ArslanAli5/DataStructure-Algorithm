#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#define SIZE 50


typedef struct stack {
   int array[SIZE];
   int top;
}stack;


void push(stack *st, int e);
int pop(stack *st);
int peek(stack *st);
int isEmpty(stack *st);
int isFull(stack *st);
void init_stk(stack *st);
void display(struct stack *st); 
void main()
{
    char array[30];
    stack stack1;
    init_stk(&stack1);
    printf("Enter the Expression: ");
    scanf("%s", array);
    fflush(stdin);
    
    int size = strlen(array);
    //printf("%d\n",size);
    for (int i=0 ; i < size; i++)
    {
        //printf("%d\n",array[i]==array[size-i-1]);
        push(&stack1, array[i]);
        if (array[i]==array[size-i-1])
        {
            pop(&stack1);
        }
    }
    //display(&stack1);
    printf("\n%s a plindrome!\n", isEmpty(&stack1) ? "String is" : "String is not");

}



void init_stk(stack *st) 
{
   st->top = -1;
}

void push(stack *st, int e)
{
    if(isFull(st))
    {
        printf("Stack overflow\n");
    }
    else
    {
        st->top = st->top + 1;
        st->array[st->top] = e;
    }
}
int peek(stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack is empty");
        return -99999;
    }
    else
    {
        return st->array[st->top];
    }
}
int pop(stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack is empty");
        return -99999;
    }
    else
    {
        int e = st->array[st->top];
        st->top = st->top - 1;
        return e;
    }
}

int isEmpty(stack *st)
{
    return (st->top==-1);
}

int isFull(stack *st)
{
    return (st->top==SIZE-1);
}

void display(struct stack *st) 
{
   int i;
   for (i = 0; i <= st->top; i++)
      printf("\n%c", st->array[i]);
}
