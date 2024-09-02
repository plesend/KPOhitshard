#include <iostream>
#include <windows.h>
#include "D:\������������ ������\���\lab_6\SE_Lab06S\SE_Lab06L\Dictionary.h"

#pragma comment(lib, "D:\\������������ ������\\���\\lab_6\\SE_Lab06S\\Debug\\SE_Lab06L.lib")
using namespace std;
using namespace Dictionary;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	try
	{
		Dictionary::Instance d1 = Dictionary::Create("�������������", 5); // �������� �������
		Dictionary::Entry e1 = { 1, "�������" }, // ������ �������
			e2 = { 2, "������" },
			e3 = { 3, "�������" },
			e4 = { 4, "�����" },
			e5 = { 5, "�������" };

		Dictionary::addEntry(d1, e1);  // ���������� ������ � �������
		Dictionary::addEntry(d1, e2);
		Dictionary::addEntry(d1, e3);
		Dictionary::addEntry(d1, e4);
		Dictionary::addEntry(d1, e5);

		Dictionary::DelEntry(d1, 2);

		Entry new_entry1 = { 6, "�������" };
		Dictionary::UpdEntry(d1, 3, new_entry1);

		Dictionary::Print(d1);
		Dictionary::Instance d2 = Dictionary::Create("��������", 5);
		Dictionary::Entry  s1 = { 1, "������" }, s2 = { 2, "������" }, s3 = { 3, "�������" };
		Dictionary::addEntry(d2, s1);
		Dictionary::addEntry(d2, s2);
		Dictionary::addEntry(d2, s3);
		Dictionary::Entry new_entry2 = { 4, "��������" };
		Dictionary::UpdEntry(d2, 3, new_entry2);
		Dictionary::Print(d2);

		cout << endl;
		Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);  // ��������� ������ �� id 4
		Dictionary::Delete(d1);
		Dictionary::Delete(d2);
	}
	catch (const char* e) {
		cout << e << endl;
	}
	system("pause");
	return 0;
}