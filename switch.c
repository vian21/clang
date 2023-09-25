#include <stdio.h>

int main()
{
    int i = 0;

    for (; i < 10; i++)
    {
        switch (i)
        {
        case i % 2 == 0:
            printf("%d odd\n", i);
            break;
        default:
            printf("%d not even\n", i);
        }
    }

    return 0;
}