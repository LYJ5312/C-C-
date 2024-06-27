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
        printf("메뉴를 선택해주세요(1. 주소록 추가, 2. 주소록 조회, 3.주소록 삭제, 4. 프로그램 종료) : ");
        scanf("%d", &menu);

        if (menu == 1) {
            printf("주소록 추가\n");
            printf("나이를 입력해주세요 :");
            scanf("%d", &people[i].age);
            printf("이름을 입력해주세요 :");
            scanf("%s", &people[i].name);
            printf("주소를 입력해주세요 :");
            scanf("%s", &people[i].address);
            ++numPeople;
        }
        else if (menu == 2) {
            printf("주소록 조회\n");
            for (int i = 0; i < numPeople; i++) {
                printf("%d번째 사람의 나이, 이름 : %d, %s, %s\n", i + 1, people[i].age, &people[i].name, &people[i].address);
            }
        }
        else if (menu == 3) {
            printf("주소록 삭제\n");
            printf("몇번째 주소록을 삭제하시겠습니까:");
            scanf("%d", &del_idx);

            for (int i = del_idx - 1; i < numPeople - 1; ++i) {
                people[i] = people[i + 1];
            }
            numPeople--;
        }

        else if (menu == 4) {
            printf("프로그램 종료합니다.\n");
            break;
        }
        else {
            printf("알 수 없는 명령입니다.\n");
        }
    }





    return 0;
}
