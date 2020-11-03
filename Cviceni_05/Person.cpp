#include "Person.h"

Entity::Person::Person() : name(""), phoneNumber(""), id(0) {}

Entity::Person::Person(string name, string phoneNumber, int id) 
{
    this->id = id;
    this->name = name;
    this->phoneNumber = phoneNumber;
}

Entity::Person::~Person(){}

int Entity::Person::getId() const { return id; }

string Entity::Person::getName() const{ return name; }

string Entity::Person::getPhoneNumber() const{ return phoneNumber; }

void Entity::Person::setId(int id) { this->id = id; };

void Entity::Person::setName(string name) { this->name = name; };

void Entity::Person::setPhoneNumber(string number) { this->phoneNumber = number; };

