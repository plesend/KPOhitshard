#include "stdafx.h"

void nameMonth(int monthInt) {
	if (monthInt < 12 && monthInt > 0) {
		string monthName[12] = {"€нварь", "февраль", "март", "апрель", "май", "июнь", "июль", "август", "сент€брь", "окт€брь", "но€брь", "декабрь"};
		cout << monthName[monthInt - 1] << endl;
	}
}