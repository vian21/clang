#include <stdio.h>
int main(){
    char array[5] = "hello";
    int arrayI[3] = {1,1,1};
    float arrayF[2] = {1.0, 2.0};

    printf("Size of int: %ld bytes\n", sizeof(int));
    printf("Size of short int: %ld bytes\n", sizeof(short int));
    printf("Size of long int: %ld bytes\n\n", sizeof(long));

    printf("Size of float: %ld bytes\n", sizeof(float));
    printf("Size of double: %ld bytes\n", sizeof(double));
    printf("Size of short double: %ld bytes\n", sizeof(double));
    printf("Size of long double: %ld bytes\n", sizeof(long double));

    printf("Size of char: %ld bytes\n", sizeof(char));

    printf("Size of byte: %ld bytes\n", sizeof(unsigned char));

    printf("Size of void*: %ld bytes\n", sizeof(void*));
    printf("Size of int*: %ld bytes\n", sizeof(int*));
    printf("Size of char*: %ld bytes\n", sizeof(char*));



    for(int i=0; i<sizeof(array)/sizeof(char); i++){
        putchar(array[i]);
    }
    putchar('\n');
    return 0;
}