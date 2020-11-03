#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;

namespace Entity 
{
	class Person
	{
	private:
		string name;
		string phoneNumber;
		int id;
	public:
		Person();
		Person(string name, string phoneNumber, int id);
		~Person();

		int getId() const;
		string getName() const;
		string getPhoneNumber() const;
		void setId(int id);
		void setName(string name);
		void setPhoneNumber(string number);
	};
}
#endif



