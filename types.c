#include <stdio.h>

int main()
{
    static int unitialised;
    static char unitialisedC;
    static char* unitialisedString;

    int integer = 11;
    int a = 0xf;
    unsigned int a =10000;
    long myLong = 10;
    float b = 10 / 3;
    double c = 10 / 3;
    unsigned char h = 'h';
    char *hello = "hello\bworld";

    int x = integer++;
    int y = (int) ++myLong;
    
    printf("unitialised: %d\n", unitialised + 1);
    printf("unitialisedChar: %c\n", unitialisedC);    
    printf("unitialisedString: %s\n", unitialisedString);    

    printf("%d %d %ld %.2f %.16f %c\n", integer,a, myLong, b, c, h);
    printf("x: %d y: %d \n", x, y);

    return 0;  //return with no errord
}