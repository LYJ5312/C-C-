// ���� : ����� ���̸� �������ּ���.

// ����¿���
/*

����� ���ڸ� �Է����ּ���. : 2[����]
1��° ����� ���̸� �Է����ּ��� : 33[����]
1��° ����� �̸��� �Է����ּ��� : aaa[����]
2��° ����� ���̸� �Է����ּ��� : 50[����]
2��° ����� �̸��� �Է����ּ��� : bbb[����]

1��° ����� ����, �̸� : 33, aaa
2��° ����� ����, �̸� : 50, bbb

*/

#include <stdio.h>
#include <stdlib.h>


int main(void) {

    int person;
    printf("����� ���ڸ� �Է����ּ���: ");
    scanf("%d", &person);

    int* mAge = malloc(sizeof(int) * person);
    char* names = malloc(20 / person);


    for (int i = 0; i < person; i++) {
        printf("%d��° ����� ���̸� �Է����ּ��� :", i + 1);
        scanf("%d", &mAge[i]);

        printf("%d��° ����� �̸��� �Է����ּ���:", i + 1);
        scanf("%s", &names[i * 4]);

    }
    printf("\n");
    for (int i = 0; i < person; i++) {
        printf("%d��° ����� ����, �̸�: %d, %s\n", i + 1, mAge[i], &names[i * 4]);
    }


    return 0;
}