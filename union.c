#include <stdio.h>

union User{
    int id;
    char groupHandle[4];
    };

int main(){
    union User user = {.id=100};
    printf("%d\n", 'd');
    printf("id: %d groupHandle: %s\n", user.id, user.groupHandle);
    return 0;
}