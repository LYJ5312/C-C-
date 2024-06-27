// 문제 : 구조체 변수의 주소를 이용해서 원본값을 변경하는 함수를 구현해주세요.
// 조건 : 아래와 같이 출력하게 해주세요.
#include <stdio.h>

struct School {
	char* name;
	int birth_date;
};

// 멤버연산(.)이 역참조 연산(*)보다 우선한다.
void change(struct School* school) {
	school->name = "미국초등학교";
	school->birth_date = 20180717;
}

int main(void) {

	struct School s1;
	s1.name = "한국초등학교";
	s1.birth_date = 19860404;

	printf("학교의 이름 : %s\n", s1.name);
	// 출력 => 학교의 이름 : 한국초등학교
	printf("학교의 설립일 : %d\n", s1.birth_date);
	// 출력 => 학교의 설립일 : 19860404

	change(&s1); // 이부분 수정 가능

	printf("학교의 이름 : %s\n", s1.name);
	// 출력 => 학교의 이름 : 미국초등학교
	printf("학교의 설립일 : %d\n", s1.birth_date);
	// 출력 => 학교의 설립일 : 20180717

	return 0;
}
