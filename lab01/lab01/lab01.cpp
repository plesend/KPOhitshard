#include "stdafx.h"

int main()
{
    int todaysDate = 0, left = 0;
    int daysArray[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    setlocale(0, "");
    string dateBD, dateTD, day, month, year, Bday, Bmonth, Byear;
    
    cout << "Я родилась ";
    cin >> dateBD;
    cout << "Введите сегодняшнюю дату в формате ДДММГГГГ ";
    cin >> dateTD;

    if (dateTD.size() != 8) {
        cout << "Вы ошиблись в дате!";
        return 0;
    }
    if (dateBD.size() != 8) {
        cout << "Вы ошиблись в дате!";
        return 0;
    }

    Bday = dateBD.substr(0, 2);
    Bmonth = dateBD.substr(2, 2);
    Byear = dateBD.substr(4, 7);

    int BdayInt = stoi(Bday); 
    int BmonthInt = stoi(Bmonth);
    int ByearInt = stoi(Byear);

    day = dateTD.substr(0, 2);
    month = dateTD.substr(2, 2);
    year = dateTD.substr(4, 7);

    int dayInt = stoi(day); 
    int monthInt = stoi(month);
    int yearInt = stoi(year);

    checkValidation(BdayInt, BmonthInt, ByearInt, daysArray);
    checkValidation(dayInt, monthInt, yearInt, daysArray);

    int countBD = countTodaysDate(BdayInt, BmonthInt, daysArray);
    int countTD = countTodaysDate(dayInt, monthInt, daysArray);

    makeLeft(yearInt, countBD, countTD, left);
    
    cout << "Порядковый номер сегодняшнего дня - " << countTD << endl;
    left += countBD - countTD;
    cout << "До дня Рождения осталось - " << left << endl;
    cout << "Месяц - "; 
    nameMonth(monthInt);
    congrat(countTD);

    system("Pause");
}






