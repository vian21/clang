#include <stdio.h>

int main()
{
    int a = 7;  // 111
    int b = 15; // 1111
    int c = 5;  // 101
    int or = 7 | 1;
    int xor = 7 ^ 1;

    printf("a:%b, b: %b, c: %b\n", a, b, c);

    printf("%b AND %b: %b\n", a, c, a & c);
    printf("%b AND %b: %b\n", b, a, b & a);
    printf("%b AND %b: %b\n\n", a, b, a & b);

    printf("%b OR %b: %b\n", a, c, a | c);
    printf("%b OR %b: %b\n", b, a, b | a);
    printf("%b OR %b: %b\n\n", a, b, a | b);

    printf("%b xOR %b: %b\n", a, c, a ^ c);
    printf("%b xOR %b: %b\n", b, a, b ^ a);
    printf("%b xOR %b: %b\n\n", a, b, a ^ b);

    for (int i = 0; i <= 5; i++)
    {
        printf("%d (%b) LEFT SHIFT %d (%b): %d (%b)\n", a, a, i, i, a << i, a << i);
    }

    printf("\n");

    for (int i = 0; i <= 5; i++)
    {
        printf("%d (%b) LEFT SHIFT %d (%b): %d (%b)\n", a, a, i, i, a >> i, a >> i);
    }
}
