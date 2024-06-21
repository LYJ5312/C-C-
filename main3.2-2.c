// 문제 : 사람의 나이를 저장해주세요.

// 입출력예시
/*

사람의 숫자를 입력해주세요. : 2[엔터]
1번째 사람의 나이를 입력해주세요 : 33[엔터]
1번째 사람의 이름을 입력해주세요 : aaa[엔터]
2번째 사람의 나이를 입력해주세요 : 50[엔터]
2번째 사람의 이름을 입력해주세요 : bbb[엔터]

1번째 사람의 나이, 이름 : 33, aaa
2번째 사람의 나이, 이름 : 50, bbb

*/

#include <stdio.h>
#include <stdlib.h>


int main(void) {

    int person;
    printf("사람의 숫자를 입력해주세요: ");
    scanf("%d", &person);

    int* mAge = malloc(sizeof(int) * person);
    char* names = malloc(20 / person);


    for (int i = 0; i < person; i++) {
        printf("%d번째 사람의 나이를 입력해주세요 :", i + 1);
        scanf("%d", &mAge[i]);

        printf("%d번째 사람의 이름을 입력해주세요:", i + 1);
        scanf("%s", &names[i * 4]);

    }
    printf("\n");
    for (int i = 0; i < person; i++) {
        printf("%d번째 사람의 나이, 이름: %d, %s\n", i + 1, mAge[i], &names[i * 4]);
    }


    return 0;
}