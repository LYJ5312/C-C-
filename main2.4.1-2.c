#include <stdio.h>

int main(void) {

    char p[5] = { 10, 20, 30, 40, 50 };

    // 1. [] ����

    for (int i = 0; i < 5; i++) {
        printf("%d\n", p[0 + i]);
    }
    // 2. ������ ���� - []���� �ʰ�
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
    // ��� :
    /*
       10
       20
       30
       40
       50
    */

    return 0;
}