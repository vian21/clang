#include <stdio.h>

enum Gender {MALE, FEMALE};

typedef enum Status{
    SINGLE,
    MARRIED
}Status;

Status getStatus();

int main(void){
    int king = MALE;
    Status status = MARRIED;

    printf("king is: %d\n", king);
    printf("king is: %d\n", getStatus());

    return 0;
}

Status getStatus(){
    return 10;
}