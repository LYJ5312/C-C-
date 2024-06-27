// 문제 : 사람의 나이와 이름을 저장해주세요.
// 조건 : 저장 개수에 제한이 없어야 하며 메모리를 효율적으로 사용해주세요.

// 입출력예시
/*
사람의 숫자를 입력해주세요. : 5[엔터]

1번째 사람의 나이를 입력해주세요 : 33[엔터]
1번째 사람의 이름을 입력해주세요 : aaa[엔터]
2번째 사람의 나이를 입력해주세요 : 50[엔터]
2번째 사람의 이름을 입력해주세요 : bbb[엔터]
3번째 사람의 나이를 입력해주세요 : 44[엔터]
3번째 사람의 이름을 입력해주세요 : ccc[엔터]
4번째 사람의 나이를 입력해주세요 : 23[엔터]
4번째 사람의 이름을 입력해주세요 : ddd[엔터]
5번째 사람의 나이를 입력해주세요 : 60[엔터]
5번째 사람의 이름을 입력해주세요 : eee[엔터]

1번째 사람의 나이, 이름 : 33, aaa
2번째 사람의 나이, 이름 : 50, bbb
3번째 사람의 나이, 이름 : 44, ccc
4번째 사람의 나이, 이름 : 23, ddd
5번째 사람의 나이, 이름 : 60, eee



*/
#include <stdio.h>
#include <stdlib.h>
struct Person {
    int age;
    char* name;
};


int main(void) {
    int numPeople;
    printf("사람의 숫자를 입력해주세요: ");
    scanf("%d", &numPeople);
    struct Person* people = malloc(numPeople * sizeof(struct Person)); //struct Person은 12바이트 -> int age >4바이트 ,char* name > 8바이트(주소)
    //사람 하나 저장하려면 총 12바이트 필요 때문에 (인원수 * 인당 저장공간12바이트) 



    for (int i = 0; i < numPeople; i++) {
        printf("%d번째 사람의 나이를 입력하세요: ", i + 1);
        scanf("%d", &people[i].age);
        printf("%d번째 사람의 이름을 입력하세요: ", i + 1);
        scanf("%s", &people[i].name);
    }
    printf("\n");

    for (int i = 0; i < numPeople; i++) {
        printf("%d번째 사람의 나이, 이름 :%d, %s \n", i + 1, people[i].age, &people[i].name);
    }




    return 0;
}