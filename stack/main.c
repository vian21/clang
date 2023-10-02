#include <stdio.h>
#include "stack.h"

int main(void)
{

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", i);
        push(i);
    }

    printf("\n");

    while (!is_empty())
    {
        Result value = pop();

        if (value.is_ok)
            printf("%d ", value.value);
    }

    printf("\n");

    push(19);
    pop();
    Result r = pop();
    printf("%s\n", r.error);
    printf("\nis_empty: %s\n ", is_empty() ? "true" : "false");

    return 0;
}