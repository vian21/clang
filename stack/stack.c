#include <stdio.h>
#include "stack.h"
#include "Result.h"

static Stack stack;
static int top = -1;

int push(int value)
{
    if (top == MAX_SIZE - 1)
        return 0;

    stack.storage[++top] = value;
    return 1;
}

Result pop()
{
    if (is_empty())
        return Err("Empty stack");

    return Ok(stack.storage[top--]);
}

int is_empty()
{
    return top == -1;
}