#include <stdio.h>
#include <stdlib.h>

struct Person {
    int age;
    char name[20];
    char address[30];
};

int main(void) {

    int menu = 0;
    int numPeople = 0;
    struct Person people[100];
    int del_idx;


    for (int i = 0; ; ++i) {
        printf("�޴��� �������ּ���(1. �ּҷ� �߰�, 2. �ּҷ� ��ȸ, 3.�ּҷ� ����, 4. ���α׷� ����) : ");
        scanf("%d", &menu);

        if (menu == 1) {
            printf("�ּҷ� �߰�\n");
            printf("���̸� �Է����ּ��� :");
            scanf("%d", &people[i].age);
            printf("�̸��� �Է����ּ��� :");
            scanf("%s", &people[i].name);
            printf("�ּҸ� �Է����ּ��� :");
            scanf("%s", &people[i].address);
            ++numPeople;
        }
        else if (menu == 2) {
            printf("�ּҷ� ��ȸ\n");
            for (int i = 0; i < numPeople; i++) {
                printf("%d��° ����� ����, �̸� : %d, %s, %s\n", i + 1, people[i].age, &people[i].name, &people[i].address);
            }
        }
        else if (menu == 3) {
            printf("�ּҷ� ����\n");
            printf("���° �ּҷ��� �����Ͻðڽ��ϱ�:");
            scanf("%d", &del_idx);

            for (int i = del_idx - 1; i < numPeople - 1; ++i) {
                people[i] = people[i + 1];
            }
            numPeople--;
        }

        else if (menu == 4) {
            printf("���α׷� �����մϴ�.\n");
            break;
        }
        else {
            printf("�� �� ���� ����Դϴ�.\n");
        }
    }





    return 0;
}
