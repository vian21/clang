#include <stdio.h>

#define MAX 100 200

#define square(x) x*x
#define max(A,B) ((A)>(B))? (A) : (B) 

int main(){
    int x = max(10,30);
    int s = square(3);
    int t = square(s+1);

    printf("%d\n", x);
    printf("%d\n", s);
    printf("%d\n", t);

    return 0;
}