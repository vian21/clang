#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack stack = createStack(INTERGER);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", i);
        push(&stack, i);
    }

    printf("\n");

    while (!is_empty(&stack))
    {
        Result value = pop(&stack);

        if (value.is_ok)
        {
            printf("%d ", value.value);
        }
    }

    printf("\n");
    pop(&stack);
    pop(&stack);
    printf("\nis_empty: %s\n ", is_empty(&stack) ? "true" : "false");

    return 0;
}