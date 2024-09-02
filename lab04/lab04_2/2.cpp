#include <iostream>

using namespace std;

typedef string surname;
typedef string name;
typedef string patronymic;
typedef unsigned int age;
typedef string gender;
typedef string speciality;
typedef unsigned int course;
typedef unsigned char group;
typedef unsigned char mid;
typedef unsigned int skip;

struct student {
	surname personSurname;
	name personName;
	patronymic personPatronymic;
	age age;
	gender f;
	speciality programmer;
	course c;
	group g;
	mid npn;
	skip s;
};

//���������� >
bool operator > (student student1, student student2) {
	return (student1.npn > student2.npn);
}
//���������� <
bool operator < (student student1, student student2) {
	return (student1.age < student2.age);
}
//���������� +
int operator + (student student1, student student2) {
	return (student1.age + student2.age);
}

int main() {
	setlocale(LC_ALL, "rus");

	int sum;

	student student1 = { "��������", "���������", "���������", 17, "�������", "�������-�����������", 1 , 6, 6.3, 4 };
	student student2 = { "����������", "��", "����������", 20, "�������", "�������-���������", 3 , 5, 8.2, 0 };

	if (student1 < student2) cout << "��������� ������ ��" << endl;
	else cout << "�� ������ ���������" << endl;

	sum = student1 + student2;
	cout << sum << endl;

	if (student1 > student2) cout << "�� �����������????????" << endl;
	else cout << "�� ������� �� �����������, � ��� ���������..." << endl;

}