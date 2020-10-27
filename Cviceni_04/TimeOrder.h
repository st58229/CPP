#pragma once
#ifndef TIMEO_H
#define TIMEO_H
#include "IComparable.h"

struct TimeOrder : public IComparable
{
private:
	int _hours;
	int _minutes;
	int _seconds;

public:	
	static void Order(IComparable** field, int size);
};

#endif 
