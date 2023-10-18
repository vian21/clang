#include <stdio.h>
// #include <stdlib.h>

int main()
{
    int a;
    char name[10];

    printf("Enter name:");

    fgets(name, 10, stdin);

    printf("Enter age:");
    scanf("%d", &a); // can be overflowed

    printf("Your name is %s and your age is %d\n", name, a);
    return 0;
}