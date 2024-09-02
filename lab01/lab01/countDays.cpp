#include "stdafx.h"
int countTodaysDate(int day, int month, int daysArray[]) {
    int count = 0;
    for (int i = 0; i < month - 1; i++) {
        count += daysArray[i];
    }
    count = count + day;

    return count;
}