#include <stdio.h>

int main(void) {

    char p[5] = { 10, 20, 30, 40, 50 };

    // 1. [] 문법

    for (int i = 0; i < 5; i++) {
        printf("%d\n", p[0 + i]);
    }
    // 2. 포인터 문법 - []쓰지 않고
    char* pp = &p;
    printf("%d\n", *pp);
    ++pp;
    printf("%d\n", *pp);
    ++pp;
    printf("%d\n", *pp);
    ++pp;
    printf("%d\n", *pp);
    ++pp;
    printf("%d\n", *pp);
    // 출력 :
    /*
       10
       20
       30
       40
       50
    */

    return 0;
}