#include "Date.h"
#include <iostream>
#include <sstream>

void Date::set_Date(int day_x, int month_x, int year_x) {
    this->day = day_x;
    this->month = month_x;
    this->year = year_x;
}
Date::Date(string s) {
    stringstream ss(s);
    string d, m, y;
    getline(ss, d, '.');
    getline(ss, m, '.');
    getline(ss, y, '.');
    day = stoi(d);
    month = stoi(m);
    year = stoi(y);
    if (month < 1 || month > 12) {          //от 1 до 12 мес€цев
        cout << "Wrong date!" << endl;
        month = 1;
    }
    for (int i = 1; i < 12; i += 2) {        //от 1 до 31 дн€
        if ((month == i) && (day > 31 || day < 1)) {
            cout << "Wrong date!" << endl;
            if (day > 31) {
                day = 31;
            }
            else {
                if (day < 0) {
                    day = 1;
                }
            }
            if (i == 7) {
                i--;
            }
        }
    }

    if (year % 4 == 0 && month == 2 && day > 29) {    //¬ысокосный, от 1 до 29 дней
        cout << "Wrong date!" << endl;
        day = 29;
        if (day < 1) {
            day = 1;
        }
    }
    if (year % 4 != 0 && month == 2 && day > 28) {    //Ќе высокосный, от 1 до 28 дней
        cout << "Wrong date!" << endl;
        day = 28;
        if (day < 1) {
            day = 1;
        }
    }
    for (int i = 4; i < 11; i += 2) {          //от 1 до 30 дней
        if (month == i && (day > 30 || day < 1)) {
            cout << "Wrong date!" << endl;
            if (day > 30) {
                day = 30;
            }
            if (day < 1) {
                day = 1;
            }
        }
        if (i == 6) {
            i++;
        }
    }
}
bool Date::operator==(Date& dat) {
    if (day == dat.day && month == dat.month && year == dat.year) {
        return true;
    }
    else return false;
}
string Date::get_Date() {
    return (to_string(day) + '.' + to_string(month) + '.' + to_string(year));
}

Date::Date() {
    day = 0;
    month = 0;
    year = 0;
}
Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
    if (month < 1 || month > 12) {          //от 1 до 12 мес€цев
        cout << "Wrong date!" << endl;
        month = 1;
    }
    for (int i = 1; i < 12; i += 2) {        //от 1 до 31 дн€
        if ((month == i) && (day > 31 || day < 1)) {
            cout << "Wrong date!" << endl;
            if (day > 31) {
                day = 31;
            }
            else {
                if (day < 0) {
                    day = 1;
                }
            }
            if (i == 7) {
                i--;
            }
        }
    }

    if (year % 4 == 0 && month == 2 && day > 29) {    //¬ысокосный, от 1 до 29 дней
        cout << "Wrong date!" << endl;
        day = 29;
        if (day < 1) {
            day = 1;
        }
    }
    if (year % 4 != 0 && month == 2 && day > 28) {    //Ќе высокосный, от 1 до 28 дней
        cout << "Wrong date!" << endl;
        day = 28;
        if (day < 1) {
            day = 1;
        }
    }
    for (int i = 4; i < 11; i += 2) {          //от 1 до 30 дней
        if (month == i && (day > 30 || day < 1)) {
            cout << "Wrong date!" << endl;
            if (day > 30) {
                day = 30;
            }
            if (day < 1) {
                day = 1;
            }
        }
        if (i == 6) {
            i++;
        }
    }
}
Date::~Date() {};