#include "Result.h"

#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

typedef struct Stack
{
    size_t elemSize;
    int top;
    void *storage;
} Stack;

/* Initialises stack of type Datatype<Enum>*/
void new_stack(Stack *s, size_t n, size_t elemSize);

/*
 * inserts a value onto the stack
 * return 1 success | 0 error
 */
int push(Stack *s, void *value);

/*
 * removes a value from the stack
 */
Result pop(Stack *stack);

/* returns boolean */
int is_empty(Stack *s);

#endif