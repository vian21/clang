#include <stdio.h>

enum Gender {MALE, FEMALE};

typedef enum Status{
    SINGLE,
    MARRIED
}Status;

struct v3{
    int x,y,z;
} p1,p2;


Status getStatus();

int main(void){
    int king = MALE;
    Status status = MARRIED;

    struct v3 point = {0,1,3};
    printf("king is: %d\n", king);
    printf("king is: %d\n", getStatus());

    printf("(%d, %d, %d)\n", point.x, point.y, point.z);
    printf("(%d, %d, %d)\n", p1.x, p1.y, p1.z);
    printf("(%d, %d, %d)\n", p2.x, p2.y, p2.z);

    return 0;
}

Status getStatus(){
    return 10;
}