#include "Varfuncr.h"

int ivarparm(int n, ...) {
	int* p = &n;             // ������������� ��������� p �� ����� ���������� n
	int result = 1;          // �������������� ��������� ��������� 1

	for (int i = 1; i <= n; i++)
		result *= *(p + i);  // �������� ��������� �� �������� ���������� ���������

	return result;           // ���������� ������������ ���������
}

int svarparm(short n, ...) {
	int* p = (int*)(&n);     // ������������� ��������� p �� ����� ���������� n, ��������������� � ���� int*
	int result = 1;          // �������������� ��������� ��������� 1

	for (short i = 1; i <= n; i++)
		result *= *(p + i);  // �������� ��������� �� �������� ���������� ���������

	return result;           // ���������� ������������ ���������
}

double fvarparm(float n, ...) {
	double* p = (double*)(&n + 1); // ������������� ��������� p �� ������ �������� ����� n
	double result = (double)n;     // �������������� ��������� ��������� n, ��������������� � double
	int k = 0;

	// ����, �������������� �� ��� ���, ���� �� ���������� �������� FLT_MAX
	while (p[k] != (double)FLT_MAX) {
		result *= *(p + k); // �������� ��������� �� ������� ��������
		k++;
	}

	return result; // ���������� ������������ ���������
}

double dvarparm(double n, ...) {
	double* p = &n;      // ������������� ��������� p �� ����� ���������� n
	double result = 1;   // �������������� ��������� ��������� 1
	int k = 0;           // ������� ��� �������� ����������

	// ����, �������������� �� ��� ���, ���� �� ���������� �������� DBL_MAX
	while (p[k] != DBL_MAX) {
		result *= *(p + k); // �������� ��������� �� ������� ��������
		k++;
	}

	return result; // ���������� ������������ ���������
}


int main() {
	cout << ivarparm(3, 2, 4, 5) << std::endl;
	cout << svarparm(2, 3, 2) << std::endl;
	cout << fvarparm(1.5, 2.0, 3.5, 4.0, FLT_MAX) << std::endl;
	cout << dvarparm(1.5, 2.5, 5.5, 7.0, DBL_MAX) << std::endl;

	return 0;
}
