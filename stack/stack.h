#include "Result.h"

#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

typedef enum Datatype
{
    INTERGER,
    CHARACTER,
    FLOAT,
    DOUBLE,
} Datatype;

typedef struct Stack
{
    Datatype type;
    int top;
    void *storage;
} Stack;

/* Create a new stack of type Datatype<Enum>*/
Stack createStack(Datatype type);

/*
 * inserts a value onto the stack
 * return 1 success | 0 error
 */
int push(Stack *, int);

/*
 * removes a value from the stack
 */
Result pop(Stack *);

/* returns boolean */
int is_empty(Stack *);

#endif