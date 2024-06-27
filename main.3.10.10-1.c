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
    printf("�ȳ��ϼ��� ���� %d�� %d�� %s�̰��, ���� ���Ӽ������� %d�� %s������ %s �������̽ʴϴ�.\n",
        s->no, s->age, s->name,
        s->teacher->age, s->teacher->subject, s->teacher->name);
}

int main(void) {
    // �� �л��鿡�� ���� ������ ������ �����ϰ� ������ּ���.
    struct Teacher t1 = { "�̼���", 45, "����" };
    struct Teacher t2 = { "�Ӳ���", 52, "ü��" };

    struct Student s1 = { 1, "ȫ�浿", 20, &t1 };
    struct Student s2 = { 2, "ȫ���", 21, &t2 };

    introduce(&s1);
    introduce(&s2);

    s1.teacher = &t2;
    s2.teacher = &t1;

    printf("\n�� ����� ���Ӽ������� �ٲ�����ϴ�.\n");

    introduce(&s1);
    introduce(&s2);


    // ��� : �ȳ��ϼ��� ���� 1�� 20�� ȫ�浿�̰��, ���� ���Ӽ������� 45�� ��������� �̼��� �������̽ʴϴ�.

    // ��� : �ȳ��ϼ��� ���� 2�� 21�� ȫ����̰��, ���� ���Ӽ������� 52�� ü�������� �Ӳ��� �������̽ʴϴ�.


    // �� ����� ���Ӽ������� �ٲ�����ϴ�. �Ʒ��� ���� ������ּ���. 


    // ��� : �ȳ��ϼ��� ���� 1�� 20�� ȫ�浿�̰��, ���� ���Ӽ������� 52�� ü�������� �Ӳ��� �������̽ʴϴ�.

    // ��� : �ȳ��ϼ��� ���� 2�� 21�� ȫ����̰��, ���� ���Ӽ������� 45�� ��������� �̼��� �������̽ʴϴ�.

    return 0;
}