#include "Address.h"

using namespace std;

Address::Address()
{
}

Address::Address(string _street, string _city, int _postal)
{
	this->_street = _street;
	this->_city = _city;
	this->_postal = _postal;
}

Address::~Address()
{
}

ostream& operator<<(ostream& read, const Address& data)
{
	read << data._street << " " << data._city << " " << data._postal;
	return read;
}

istream& operator>>(istream& write, Address& data)
{
	write >> data._street;
	write >> data._city;
	write >> data._postal;

	return write;
}
