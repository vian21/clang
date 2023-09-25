#include "stack.h"

int array[MAX_SIZE];
int top;

int push(int value){
    printf("Top%d\n", top);
    if(top == MAX_SIZE -1) return 0;

    array[++top] = value;
    return 1;
}

int pop(){
    if(is_empty()) return -1;

    return array[top--];
}

int is_empty(){
    return top == -1;
}