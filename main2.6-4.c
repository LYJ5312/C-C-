#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// 문제 : int 없이, int*와 malloc을 사용해서 함수를 다시 만들어주세요.
// 조건 : 변수를 오직 1개만 사용할 수 있습니다.
void print_99dan() {

	int* dan = malloc(8);

	for (dan[0] = 2; dan[0] < 10; (dan[0])++) {
		for (dan[1] = 1; dan[1] < 10; (dan[1])++) {
			printf("%d * %d = %d\n", dan[0], dan[1], (dan[0]) * (dan[1]));
		}
	}

}

int main(void) {

	print_99dan();

	return 0;
}