#include <stdio.h>
#include <limits.h>

struct DynArrayStack
{
    int top;
    int capacity;
    int *array;
};

struct DynArrayStack *CreateStack()
{
    struct DynArrayStack *S = malloc(sizeof(struct DynArrayStack));
    if (!S)
        return NULL;

    S->capacity = 1;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int)); //alocate an array of size 1 initially

    if (!S->array)
        return NULL;

    return S;
}

int IsFullStack(struct DynArrayStack *S)
{
    return (S->top == S->capacity - 1);
}

//UNFINISHED