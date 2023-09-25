#include <stdio.h>

int main()
{

    int i = 0;

    for (; i <= 3; i++)
        printf("%d\n", i);

    while (i <= 5)
    {
        printf("%d\n", i);
        i++;
    }

    do
    {
        printf("%d\n", i);
        i++;
    } while (i < 10);
    return 0;
}