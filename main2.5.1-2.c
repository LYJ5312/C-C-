#include <stdio.h>



void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *arr++);
    }
    printf("\n");
}

int main() {

    int arr[4] = { 1,2,3,4 };
    print_arr(arr, 4);
    // 출력 : 1 2 3 4


    int arr2[6] = { 1,2,3,4,5,6 };
    print_arr(arr2, 6);



    // 출력 : 1 2 3 4 5 6


    return 0;
}