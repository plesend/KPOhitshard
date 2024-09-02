#include <iostream>
#include <windows.h>
#include "D:\лабораторные работы\кпо\lab_6\SE_Lab06S\SE_Lab06L\Dictionary.h"

#pragma comment(lib, "D:\\лабораторные работы\\кпо\\lab_6\\SE_Lab06S\\Debug\\SE_Lab06L.lib")
using namespace std;
using namespace Dictionary;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	try
	{
		Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 5); // Создание словаря
		Dictionary::Entry e1 = { 1, "Гладкий" }, // Записи словаря
			e2 = { 2, "Тугрин" },
			e3 = { 3, "Кипелов" },
			e4 = { 4, "Шиман" },
			e5 = { 5, "Белодед" };

		Dictionary::addEntry(d1, e1);  // Добавление записи в словарь
		Dictionary::addEntry(d1, e2);
		Dictionary::addEntry(d1, e3);
		Dictionary::addEntry(d1, e4);
		Dictionary::addEntry(d1, e5);

		Dictionary::DelEntry(d1, 2);

		Entry new_entry1 = { 6, "Острога" };
		Dictionary::UpdEntry(d1, 3, new_entry1);

		Dictionary::Print(d1);
		Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
		Dictionary::Entry  s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" };
		Dictionary::addEntry(d2, s1);
		Dictionary::addEntry(d2, s2);
		Dictionary::addEntry(d2, s3);
		Dictionary::Entry new_entry2 = { 4, "Николаев" };
		Dictionary::UpdEntry(d2, 3, new_entry2);
		Dictionary::Print(d2);

		cout << endl;
		Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);  // Получение записи по id 4
		Dictionary::Delete(d1);
		Dictionary::Delete(d2);
	}
	catch (const char* e) {
		cout << e << endl;
	}
	system("pause");
	return 0;
}