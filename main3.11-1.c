// 문제 : 회원의 수를 미리 정하지 않고 한명씩 입력할 때마다 저장해주세요. 회원의 수를 알 수 없기 때문에 정적, 동적 배열 모두 사용할 수 없으며 
// 서로 흩어진 회원 정보들을 앞선 3명의 사람 문제처럼 서로 연결해야합니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct member {
    int age;
    char name[20];
    char address[30];
    struct Member* next;
}Member;
// 예시
/*
메뉴를 선택해주세요(1. 주소록 추가, 2. 주소록 조회, 3. 주소록 삭제, 4. 종료) : 1
나이를 입력해주세요 : 20[엔터]
이름을 입력해주세요 : 홍길동[엔터]
주소를 입력해주세요 : 대전[엔터]
주소록이 추가되었습니다.
메뉴를 선택해주세요(1. 주소록 추가, 2. 주소록 조회, 3. 주소록 삭제, 4. 종료) : 1
나이를 입력해주세요 : 50[엔터]
이름을 입력해주세요 : 임꺽정[엔터]
주소를 입력해주세요 : 경기[엔터]
주소록이 추가되었습니다.
메뉴를 선택해주세요(1. 주소록 추가, 2. 주소록 조회, 3. 주소록 삭제, 4. 종료) : 1
나이를 입력해주세요 : 23[엔터]
이름을 입력해주세요 : 황진이[엔터]
주소를 입력해주세요 : 서울[엔터]
주소록이 추가되었습니다.
메뉴를 선택해주세요(1. 주소록 추가, 2. 주소록 조회, 3. 주소록 삭제, 4. 종료) : 2
== 전체 회원 리스트 ==
1번째 사람의 나이, 이름 : 20, 홍길동, 대전
2번째 사람의 나이, 이름 : 50, 임꺽정, 경기
3번째 사람의 나이, 이름 : 23, 황진이, 서울

*/



int main(void) {
    int menu = 0;
    int numPeople = 0;
    int count = 1;
    int del_idx;
    Member* head = NULL;
    Member* tail = NULL;

    while (1) {
        printf("메뉴를 선택해주세요(1. 주소록 추가, 2. 주소록 조회, 3. 주소록 삭제, 4. 종료) : ");
        scanf("%d", &menu);

        if (menu == 1) {
            Member* new_member = malloc(sizeof(Member));
            printf("나이를 입력해주세요 : ");
            scanf("%d", &new_member->age);
            printf("이름을 입력해주세요 : ");
            scanf("%s", &new_member->name);
            printf("주소를 입력해주세요 : ");
            scanf("%s", &new_member->address);

            new_member->next = NULL; //next를 초기화를 안해주면 조회기능에서 조회할 주소록을 다 보여주었어도 
            //while문에서 NULL이 아니기때문에 종료가 안되고 오류터짐
            if (head == NULL) {
                head = tail = new_member;
            }
            else {
                tail->next = new_member;
                tail = new_member;
            }
            printf("주소록이 추가되었습니다.");
        }

        else if (menu == 2) {
            if (head == NULL) {
                printf("주소록이 비어있습니다.");
            }
            else {
                Member* current = head;
                int count = 1;
                while (current != NULL) {
                    printf("%d번째 사람의 나이, 이름, 주소: %d, %s, %s\n",count, current->age, current->name, current->address);
                    current = current->next;
                    count++;
                }
            }
        }
        else if (menu == 3) {
            printf("몇번째 주소록을 삭제하시겠습니까? : ");
            scanf("%d", &del_idx);

            Member* current = head;
            Member* previous = NULL;
            int count = 1;

            while (current != NULL && count < del_idx) {  //리스트가 없거나 끝이 아니고 삭제할번호까지 도달하기전까지 게속 반복
                previous = current;                       //삭제하려는 리스트가 A~Z이고 2번째인 B를 삭제한다면, A부터 current(삭제할 대상)로 지정하여 지정한 번호에 도달할때까지                       
                current = current->next;                  //previous로 넘겨줌 ex) A(current) ,B(current->next)-> A(preious) ,B(current), C(current->next)
                count++;
            }
            if (current == NULL) {
                printf("해당번호의 주소록이 없습니다.");
            }
            else {
                if (previous == NULL) { //previous가 없으면 첫번째 head를 삭제한다는것. 다음값을 head에 저장.
                    head = current->next;
                }
                else {
                    previous->next = current->next; //current가B라면 A와 C를 연결지어줘야 함

                     //삭제할 값을 삭제할 값의 다음값으로 변경
                    if (tail == current) {    //삭제할 값이 tail이라면 
                        tail = previous;      //tail을 tail의 전값으로 변경
                    }
                    free(current);
                    printf("%d번째 주소록이 삭제되었습니다.", del_idx);
                }
            }
        }
        else if (menu == 4) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("알수없는 명령입니다.");
        }
    }

    return 0;
}
