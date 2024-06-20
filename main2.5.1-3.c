// 문제 : 배열을 훼손하는 change 함수를 만들어주세요.

#include <stdio.h>
// 여기서 change 함수를 구현해주세요.
// 
//처음 구상한거
void change(int* px) {
    for (int i = 0; i < 2; i++) {
        *px = *px * 2;
        *px++;
    }
}
// 1. [] 이용
void change(int arr[]) {
    arr[0] = 200;
    arr[1] = 400;
}
// 2. [] 이용 X
void change(int* arr) {
    *arr = 200;
    *(arr + 1) = 400;
}
int main(void) {

    int x[2];
    x[0] = 100;
    x[1] = 200;
    //int x[2] = {100, 200}; // 위 3 줄 코드의 같은 의미이다.

    printf("change 함수를 호출하기 전, x[0] : %d, x[1] : %d\n", x[0], x[1]);

    printf("x의 크기 : %lu\n", sizeof(x));

    // 여기서 change 함수를 실행해주세요.
    change(x);

    printf("change 함수를 호출하기 전, x[0] : %d, x[1] : %d\n", x[0], x[1]);
    // 출력 => change 함수를 호출하기 전, x[0] : 200, x[1] : 400

    return 0;
}

