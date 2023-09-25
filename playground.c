#include <stdio.h>

int add(int a, int b);
int power(int x, int n);

int main()
{

    printf("Add: %d\n", add(1, 4));
    printf("Power: %d\n", power(2, 3));

    printf("Power: %d\n", power(2, 4));

    return 0;
}
