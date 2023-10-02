#include <stdio.h>

double add(int, int);
int getA(char);
int main()
{

    printf("%d %d\n", (int)add(1, 20), 'c');
    // int c = getline();

    return 0;
}

// int strlen(){}
double add(int a, int b)
{
    return a + b;
}

int getA(char c)
{
    return c;
}