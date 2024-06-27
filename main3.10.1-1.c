#include <stdio.h>
struct Teacher {
    char name[20];
    int age;
    char subject[20];
};

struct Student {
    int no;
    char name[20];
    int age;
    struct Teacher* teacher;
};

void introduce(struct Student* s) {
    printf("안녕하세요 저는 %d번 %d살 %s이고요, 저의 담임선생님은 %d살 %s과목의 %s 선생님이십니다.\n",
        s->no, s->age, s->name,
        s->teacher->age, s->teacher->subject, s->teacher->name);
}

int main(void) {
    // 각 학생들에게 담임 선생님 정보를 저장하고 출력해주세요.
    struct Teacher t1 = { "이순신", 45, "역사" };
    struct Teacher t2 = { "임꺽정", 52, "체육" };

    struct Student s1 = { 1, "홍길동", 20, &t1 };
    struct Student s2 = { 2, "홍길순", 21, &t2 };

    introduce(&s1);
    introduce(&s2);

    s1.teacher = &t2;
    s2.teacher = &t1;

    printf("\n두 사람의 담임선생님이 바뀌었습니다.\n");

    introduce(&s1);
    introduce(&s2);


    // 출력 : 안녕하세요 저는 1번 20살 홍길동이고요, 저의 담임선생님은 45살 역사과목의 이순신 선생님이십니다.

    // 출력 : 안녕하세요 저는 2번 21살 홍길순이고요, 저의 담임선생님은 52살 체육과목의 임꺽정 선생님이십니다.


    // 두 사람의 담임선생임이 바뀌었습니다. 아래와 같이 출력해주세요. 


    // 출력 : 안녕하세요 저는 1번 20살 홍길동이고요, 저의 담임선생님은 52살 체육과목의 임꺽정 선생님이십니다.

    // 출력 : 안녕하세요 저는 2번 21살 홍길순이고요, 저의 담임선생님은 45살 역사과목의 이순신 선생님이십니다.

    return 0;
}