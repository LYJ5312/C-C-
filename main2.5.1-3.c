// ���� : �迭�� �Ѽ��ϴ� change �Լ��� ������ּ���.

#include <stdio.h>
// ���⼭ change �Լ��� �������ּ���.
// 
//ó�� �����Ѱ�
void change(int* px) {
    for (int i = 0; i < 2; i++) {
        *px = *px * 2;
        *px++;
    }
}
// 1. [] �̿�
void change(int arr[]) {
    arr[0] = 200;
    arr[1] = 400;
}
// 2. [] �̿� X
void change(int* arr) {
    *arr = 200;
    *(arr + 1) = 400;
}
int main(void) {

    int x[2];
    x[0] = 100;
    x[1] = 200;
    //int x[2] = {100, 200}; // �� 3 �� �ڵ��� ���� �ǹ��̴�.

    printf("change �Լ��� ȣ���ϱ� ��, x[0] : %d, x[1] : %d\n", x[0], x[1]);

    printf("x�� ũ�� : %lu\n", sizeof(x));

    // ���⼭ change �Լ��� �������ּ���.
    change(x);

    printf("change �Լ��� ȣ���ϱ� ��, x[0] : %d, x[1] : %d\n", x[0], x[1]);
    // ��� => change �Լ��� ȣ���ϱ� ��, x[0] : 200, x[1] : 400

    return 0;
}

