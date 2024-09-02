#include "stdafx.h"

int makeLeft(int year, int countBD, int countTD, int& left) {
    bool leapYear = checkLeapYear(year);
    if (leapYear == true) {
        if (countBD == 60) {
            left = 1460;
        }
        else {
            if (countBD < countTD) {
                left = 366;
            }
            else
                left = 0;
        }
        
    }
    if (leapYear == false) {
        if (countBD < countTD) {
            left = 365;
        }
        else
            left = 0;
    }

    return left;
}

