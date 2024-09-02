#include "Varfuncr.h"

int ivarparm(int n, ...) {
	int* p = &n;             // Устанавливаем указатель p на адрес переменной n
	int result = 1;          // Инициализируем результат значением 1

	for (int i = 1; i <= n; i++)
		result *= *(p + i);  // Умножаем результат на значение следующего аргумента

	return result;           // Возвращаем получившийся результат
}

int svarparm(short n, ...) {
	int* p = (int*)(&n);     // Устанавливаем указатель p на адрес переменной n, преобразованный к типу int*
	int result = 1;          // Инициализируем результат значением 1

	for (short i = 1; i <= n; i++)
		result *= *(p + i);  // Умножаем результат на значение следующего аргумента

	return result;           // Возвращаем получившийся результат
}

double fvarparm(float n, ...) {
	double* p = (double*)(&n + 1); // Устанавливаем указатель p на первый аргумент после n
	double result = (double)n;     // Инициализируем результат значением n, преобразованным к double
	int k = 0;

	// Цикл, продолжающийся до тех пор, пока не встретится значение FLT_MAX
	while (p[k] != (double)FLT_MAX) {
		result *= *(p + k); // Умножаем результат на текущий аргумент
		k++;
	}

	return result; // Возвращаем получившийся результат
}

double dvarparm(double n, ...) {
	double* p = &n;      // Устанавливаем указатель p на адрес переменной n
	double result = 1;   // Инициализируем результат значением 1
	int k = 0;           // Счетчик для перебора аргументов

	// Цикл, продолжающийся до тех пор, пока не встретится значение DBL_MAX
	while (p[k] != DBL_MAX) {
		result *= *(p + k); // Умножаем результат на текущий аргумент
		k++;
	}

	return result; // Возвращаем получившийся результат
}


int main() {
	cout << ivarparm(3, 2, 4, 5) << std::endl;
	cout << svarparm(2, 3, 2) << std::endl;
	cout << fvarparm(1.5, 2.0, 3.5, 4.0, FLT_MAX) << std::endl;
	cout << dvarparm(1.5, 2.5, 5.5, 7.0, DBL_MAX) << std::endl;

	return 0;
}
