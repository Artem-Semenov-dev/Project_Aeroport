#pragma once
#include <string>
using namespace std;
class classTime {
private:
	int minutes;
	int hours;
public:
	void set_Time(int, int);
	string get_Time();
	classTime();
	classTime(string);
	classTime(int, int);
	//~Time_h();
};

