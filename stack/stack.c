#include <stdio.h>
#include "stack.h"
#include "Result.h"

Stack createStack(Datatype type)
{
    int storage[MAX_SIZE];

    return (Stack){
        .type = type,
        .top = -1,
        .storage = (void *)storage};
}

int push(Stack *s, int value)
{
    if (s->top == MAX_SIZE - 1)
        return 0;

    int *nextSpot = (int *)(s->storage) + ++(s->top);
    *nextSpot = value;

    return 1;
}

Result pop(Stack *s)
{
    if (is_empty(s))
        return Err("Empty stack");

    int value = *((int *)(s->storage) + s->top--);

    return Ok(value);
}

int is_empty(Stack *s)
{
    return (*s).top == -1;
}