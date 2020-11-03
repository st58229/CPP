#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>

#include "Person.h"

using namespace std;
namespace Model 
{
	class Phonebook
	{
		struct listElement 
		{
		public:
			listElement* next;
			Entity::Person data;
			listElement() : next(nullptr), data() {}
		};

	public:
		void addPerson(Entity::Person p);
		string FindPhone(string name) const;
		string FindPhone(int id) const;
		Phonebook();
		~Phonebook();
	private:
		listElement* start;
	};
}

#endif

