#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>

struct Date {
private:
	int _d;
	int _m;
	int _y;

public:
	Date();
	Date(int _d, int _m, int _y);
	~Date();
	friend std::ostream& operator<<(std::ostream& read, const Date& data);
	friend std::istream& operator>>(std::istream& write, Date& data);
};

#endif
