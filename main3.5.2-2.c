// 자동차 정보를 출력해주는 함수를 만들어주세요.

#include <stdio.h>

struct Car {
	char* model;
	int max_velo;
	int year;
};

// 이 함수를 완성 시켜주세요.
void print_car(struct Car car) {
	printf("모델 :%s\n 최고속력 :%d\n 연식 :%d\n", car.model, car.max_velo, car.year);
	printf("\n");
}

int main(void) {

	// 자동차 구조체 만들기
	// 모델명, 최고속력, 연식

	// 아반떼, 220, 2020
	struct Car c1 = { "아반떼", 220, 2020 };

	// 소나타, 240, 2019
	struct Car c2;
	c2.model = "소나타";
	c2.max_velo = 240;
	c2.year = 2019;

	// 산타페, 230, 2018
	struct Car c3;
	c3.model = "산타페";
	c3.max_velo = 230;
	c3.year = 2018;



	print_car(c1);
	// // 출력 : 
	// // 모델 : 아반떼 
	// // 최고속력 : 220
	// // 연식 : 2020

	print_car(c2);
	// // 출력 : 
	// // 모델 : 소나타 
	// // 최고속력 : 240
	// // 연식 : 2019

	print_car(c3);
	// // 출력 : 
	// 모델 : 산타페 
	// 최고속력 : 230
	// 연식 : 2018



	return 0;
}
