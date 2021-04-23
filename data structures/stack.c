#include <stdio.h>
#include <limits>

#define MAXSIZE 10
struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack *CreateStack()
{
    struct ArrayStack *S = malloc(sizeof(struct ArrayStack));

    if (!S)
        return NULL;

    return S;
}

int IsEmptyStack(struct ArrayStack *S)
{
    return (S->top == S->capacity - 1);
}

int IsFullStack(struct ArrayStack *S)
{
    //if the condition is true then 1 is returned else 0 is returned
    return (S->top == S->capacity - 1);
}

int Pop(struct ArrayStack *S, int data)
{
    // S-> top == -1 indicates empty stack
    if (IsEmptyStack(S))
    {
        printf("stack is empty");
        return INT_MIN;
    }

    else //Removing element from "top" of the array reducin 'top' by 1
        return (S->array[S->top--]);
}

void push(struct ArrayStack *S, int data)
{
    // S-> top == capacity -1 indicates that the stack is full
    if (IsFullStack(S))
    {
        printf("Stack Overflow");
    }

    else //omcreasomg the 'top' by 1 and storing the value at 'top' position
        S->array[++S->top] = data;
}

void DeleteStack(struct ArrayStack *S)
{
    if (S)
    {
        if (S->array)
            free(S->array);

        free(S);
    }
}