#include "IComparable.h"
#include "Time.h"
#include "IObject.h"
#include <string>

using namespace std;

Time::Time(int _hours, int _minutes, int _seconds) {
	this->_hours = _hours;
	this->_minutes = _minutes;
	this->_seconds = _seconds;
}

string Time::toString() const {
	return to_string(this->_hours) + ':' + to_string(this->_minutes) + ':' + to_string(this->_seconds);
}

int Time::compareTo(IComparable* obj) const {

	if (dynamic_cast<Time*>(obj) == nullptr)
	{
		throw;
	}

	//Hours
	if (_hours == ((Time*)obj)->_hours) {

		//Minutes
		if (_minutes == ((Time*)obj)->_minutes) {

			//Seconds
			if (_seconds == ((Time*)obj)->_seconds)			return 0;
			else if (_seconds > ((Time*)obj)->_seconds) 	return 1;
			else											return -1;			
		}
		else if (_minutes > ((Time*)obj)->_minutes)		return 1;		
		else 											return -1;		
	}
	else if (_hours > ((Time*)obj)->_hours)			return 1;	
	else											return -1;
	
}