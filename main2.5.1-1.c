#include <stdio.h>

int main(void) {

    // scanf�� �̿��ؼ� ���� 10���� �Է¹޾� �迭�� ������ �� ������ּ���.


    int arr[10];

    //1. [] �̿��ؼ�
    printf("�����Է�:");
    for (int i = 0; i < 10; i++) {
        scanf_s("%d", &arr[i]);
    }
    printf("\n");

    printf("�Է��� ����:");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    //2. [] �̿����� ����
    int* parr = &arr;
    printf("�����Է�:");
    for (int i = 0; i < 10; i++) {
        scanf_s("%d", parr++);
    }
    parr = arr;
    printf("�Է��� ����:");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *parr++);
    }
    printf("\n");

    return 0;
}