#pragma once
#ifndef TIME_H
#define TIME_H
#include "IComparable.h"

struct Time : public IComparable
{
private:
	int _hours;
	int _minutes;
	int _seconds;

public:
	Time(int _hours, int _minutes, int _seconds);
	void Order(IComparable** field, int size);
	virtual int compareTo(IComparable* obj) const override;
	virtual std::string toString() const override;
};

#endif 


