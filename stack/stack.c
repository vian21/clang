#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "Result.h"

void new_stack(Stack *s, size_t n, size_t elemSize)
{
    void *storage = malloc(n * elemSize);

    s->top = -1;
    s->elemSize = elemSize;
    s->storage = storage;
}

int push(Stack *s, void *value)
{
    if (s->top == MAX_SIZE - 1)
        return 0;

    void *nextSpot = (char *)(s->storage) + ++(s->top) * s->elemSize;

    // copy value into storage
    memcpy(nextSpot, value, s->elemSize);

    return 1;
}

Result pop(Stack *s)
{
    if (is_empty(s))
        return Err("Empty stack");

    void *value = (char *)s->storage + s->top-- * s->elemSize;

    return Ok(value);
}

int is_empty(Stack *s)
{
    return (*s).top == -1;
}