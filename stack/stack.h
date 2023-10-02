#include "Result.h"

#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

typedef struct Stack
{
    int storage[MAX_SIZE];
} Stack;

/*
 * inserts a value onto the stack
 * return 1 success | 0 error
 */
int push(int);

/*
 * removes a value from the stack
 */
Result pop(void);

/* returns boolean */
int is_empty(void);

#endif