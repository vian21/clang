#include <stdio.h>
// #include <stdlib.h>
#define NAME_LEN 3
int main()
{
    int a;
    char name[NAME_LEN];
    printf("Enter name:");

    char c = getchar();
    int count = 0;
    while (count < NAME_LEN - 1) //-1 for /0
    {
        if (c == '\n')
            break;

        name[count++] = c;
        c = getchar();
    }
    name[count] = '\0';
    fflush(stdin);
    // fgets(name, 10, stdin);

    printf("Enter age:");
    scanf("%d", &a); // can be overflowed

    printf("Your name is %s and your age is %d\n", name, a);
    return 0;
}