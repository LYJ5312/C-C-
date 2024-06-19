#include <stdio.h>

int main(void) {

    // scanf를 이용해서 숫자 10개를 입력받아 배열에 저장한 후 출력해주세요.


    int arr[10];

    //1. [] 이용해서
    printf("숫자입력:");
    for (int i = 0; i < 10; i++) {
        scanf_s("%d", &arr[i]);
    }
    printf("\n");

    printf("입력한 숫자:");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    //2. [] 이용하지 말고
    int* parr = &arr;
    printf("숫자입력:");
    for (int i = 0; i < 10; i++) {
        scanf_s("%d", parr++);
    }
    parr = arr;
    printf("입력한 숫자:");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *parr++);
    }
    printf("\n");

    return 0;
}