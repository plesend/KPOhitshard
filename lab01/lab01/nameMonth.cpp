#include "stdafx.h"

void nameMonth(int monthInt) {
	if (monthInt < 12 && monthInt > 0) {
		string monthName[12] = {"������", "�������", "����", "������", "���", "����", "����", "������", "��������", "�������", "������", "�������"};
		cout << monthName[monthInt - 1] << endl;
	}
}