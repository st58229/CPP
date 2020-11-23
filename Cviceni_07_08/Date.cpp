#include "Date.h"

using namespace std;

Date::Date()
{
}

Date::Date(int _d, int _m, int _y)
{
	this->_d = _d;
	this->_m = _m;
	this->_y = _y;
}

Date::~Date()
{
}

std::ostream& operator<<(std::ostream& read, const Date& data)
{
	read << data._d << " " << data._m << " " << data._y << endl;
	return read;
}

std::istream& operator>>(std::istream& write, Date& data)
{
	write >> data._d;
	write >> data._m;
	write >> data._y;
	return write;
}
