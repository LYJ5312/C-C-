// �ڵ��� ������ ������ִ� �Լ��� ������ּ���.

#include <stdio.h>

struct Car {
	char* model;
	int max_velo;
	int year;
};

// �� �Լ��� �ϼ� �����ּ���.
void print_car(struct Car car) {
	printf("�� :%s\n �ְ�ӷ� :%d\n ���� :%d\n", car.model, car.max_velo, car.year);
	printf("\n");
}

int main(void) {

	// �ڵ��� ����ü �����
	// �𵨸�, �ְ�ӷ�, ����

	// �ƹݶ�, 220, 2020
	struct Car c1 = { "�ƹݶ�", 220, 2020 };

	// �ҳ�Ÿ, 240, 2019
	struct Car c2;
	c2.model = "�ҳ�Ÿ";
	c2.max_velo = 240;
	c2.year = 2019;

	// ��Ÿ��, 230, 2018
	struct Car c3;
	c3.model = "��Ÿ��";
	c3.max_velo = 230;
	c3.year = 2018;



	print_car(c1);
	// // ��� : 
	// // �� : �ƹݶ� 
	// // �ְ�ӷ� : 220
	// // ���� : 2020

	print_car(c2);
	// // ��� : 
	// // �� : �ҳ�Ÿ 
	// // �ְ�ӷ� : 240
	// // ���� : 2019

	print_car(c3);
	// // ��� : 
	// �� : ��Ÿ�� 
	// �ְ�ӷ� : 230
	// ���� : 2018



	return 0;
}
