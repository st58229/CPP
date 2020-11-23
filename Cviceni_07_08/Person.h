#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Address.h"
#include "Date.h"

struct Person
{
private:
	std::string _name;
	std::string _surname;
	Address _residence;
	Date _birth;
public:
	Person();
	Person(std::string _name, std::string _surname, Address _residence, Date _birth);
	~Person();
	friend std::ostream& operator<<(std::ostream& read, const Person& data);
	friend std::istream& operator>>(std::istream& write, Person& data);
};

#endif