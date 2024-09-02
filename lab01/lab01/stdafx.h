#pragma once
#include <iostream>
#include <string>
using namespace std;

bool checkLeapYear(int toYear);
int countTodaysDate(int day, int month, int daysArray[]);
int checkValidation(int day, int month, int year, int daysArray[]);
int makeLeft(int year, int countBD, int countTD, int& left);
void nameMonth(int monthInt);
void congrat(int countTD);