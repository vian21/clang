#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void test_int();
void test_double();
void test_struct();

int main(void)
{
    test_int();

    test_double();

    test_struct();

    return 0;
}

void test_int()
{
    printf("Testing Stack<struct>\n");

    Stack stack;
    new_stack(&stack, 20, sizeof(int));

    for (int i = 0; i < 20; i++)
    {
        printf("%d ", i);
        push(&stack, (void *)&i);
    }

    printf("\n");

    while (!is_empty(&stack))
    {
        Result value = pop(&stack);

        if (value.is_ok)
        {
            printf("%d ", *(int *)(value.value));
        }
    }
    printf("\n\n");
    free(stack.storage);
}

void test_double()
{
    printf("Testing Stack<double>\n");

    Stack stackd;
    new_stack(&stackd, 20, sizeof(double));

    for (double i = 0; i < 20; i++)
    {
        printf("%.1f ", i);
        push(&stackd, (void *)&i);
    }

    printf("\n");

    while (!is_empty(&stackd))
    {
        Result value = pop(&stackd);

        if (value.is_ok)
        {
            printf("%.1f ", *(double *)(value.value));
        }
    }

    printf("\n\n");

    free(stackd.storage);
}

void test_struct()
{
    printf("Testing Stack<struct>\n");

    typedef struct
    {
        int x;
        int y;
    } Point;

    Stack stack;
    int size = 10;
    new_stack(&stack, size, sizeof(Point));

    for (int i = 0; i < size; i++)
    {
        push(&stack, (void *)&(Point){i, i * i});
    }

    while (size-- > 0)
    {
        Result value = pop(&stack);

        if (value.is_ok)
        {
            Point p = (*(Point *)value.value);
            printf("(%d, %d) ", p.x, p.y);
        }
    }

    free(stack.storage);
    printf("\n\n");
}