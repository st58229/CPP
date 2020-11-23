#include "Person.h"
#include "Date.h"
#include "Address.h"
#include <iostream>

using namespace std;

Person::Person()
{
}

Person::Person(string _name, string _surname, Address _residence, Date _birth)
{
	this->_name = _name;
	this->_surname = _surname;
	this->_residence = _residence;
	this->_birth = _birth;
}

Person::~Person()
{
}

ostream& operator<<(ostream& read, const Person& data)
{
	read << data._name << " " << data._surname << " " << data._residence << " " << data._birth;
	return read;
}

istream& operator>>(istream& write, Person& data)
{
	write >> data._name;
	write >> data._surname;
	write >> data._residence;
	write >> data._birth;
	return write;
}