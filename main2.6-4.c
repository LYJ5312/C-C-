#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// ���� : int ����, int*�� malloc�� ����ؼ� �Լ��� �ٽ� ������ּ���.
// ���� : ������ ���� 1���� ����� �� �ֽ��ϴ�.
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