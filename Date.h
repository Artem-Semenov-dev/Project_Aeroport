#pragma once
#include <string>
using namespace std;
class Date {
private:
	int day;
	int month;
	int year;
public:
	void set_Date(int, int, int);
	Date(string);
	bool operator==(Date&);
	string get_Date();
	Date();
	Date(int, int, int);
	~Date();
};
