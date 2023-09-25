#include <stdio.h>
#include "stack.h"

#define ARRAY_SIZE 10
extern int array[];

int main(void)
{

    int a[ARRAY_SIZE];
    for (int i = 0; i < 10; i++)
    {
        a[i] = i;
    }

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", a[i]);
        push(a[i]);
    }

    printf("\n");

    while (!is_empty())
    {
        printf("%d ", pop());
    }

    push(19);
    pop();
    printf("\nis_empty: %s\n ", is_empty() ? "true" : "false");

    return 0;
}