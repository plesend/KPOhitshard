#include "stdafx.h"
int checkValidation(int day, int month, int year, int daysArray[]) {
    bool leapYearChecked = checkLeapYear(year);
   
    if (day > 31) {
        cout << "�������� ��������!";
        return 0;
    }
    if (month > 12) {
        cout << "�������� ��������!";
        return 0;
    }
    if (year > 2024) {
        cout << "������ ���������!!";
        return 0;
    }
    if (day > daysArray[month]) {
        cout << "������ ��� �� ����������((";
        return 0;
    }
    if (day < 1) {
        cout << "������ ��� �� ����������((";
        return 0;
    }
    if (month < 0) {
        cout << "�������� ��������!";
        return 0;
    }
    if (year < 0) {
        cout << "������ ���������!!";
        return 0;
    }
    if (leapYearChecked == true) {
        daysArray[1] = 29;
    }
    if (leapYearChecked == false) {
        daysArray[1] = 28;
    }
    
}
