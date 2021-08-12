#include "Classtime.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
classTime::classTime() {
    minutes = 0;
    hours = 0;
}
classTime::classTime(string s) {
    stringstream ss(s);
    string min, hou;
    getline(ss, hou, '.');
    getline(ss, min, '.');
    minutes = stoi(min);
    hours = stoi(hou);
    if (hours < 0 || hours > 24) {
        cout << "wrong number of hours";
        hours = 1;
    }
    if (minutes < 0) {
        cout << "Wrong number of minutes";
        minutes = 1;
    }
    if (minutes > 61) {
        int it = 0;
        for (int i = 0; i < (minutes / 60) && hours < 24; i++) {
            hours++;
            it = i;
        }
        minutes = minutes - (it * 60);
    }
}
classTime::classTime(int min, int hou) {
    minutes = min;
    hours = hou;
    if (hours > 0 || hours < 24) {
        cout << "wrong number of hours";
        hours = 1;
    }
    if (minutes < 0) {
        cout << "Wrong number of minutes";
        minutes = 1;
    }
    if (minutes > 61) {
        int it;
        for (int i = 0; i < (minutes / 60) && hours < 24; i++) {
            hours++;
            it = i;
        }
        minutes = minutes - (it * 60);
    }
}
void classTime::set_Time(int min, int hou) {
    this->hours = hou;
    this->minutes = min;
}
string classTime::get_Time() {
    return(to_string(hours) + '.' + to_string(minutes));
}

