#include "Phonebook.h"
#include "Exceptions.h"

void Model::Phonebook::addPerson(Entity::Person p) 
{
    listElement* newElement = new listElement{};
    newElement->data = p;
    newElement->next = start;
    start = newElement;
}

string Model::Phonebook::FindPhone(string name) const 
{
    if (name._Equal("")) { throw WrongInputException("NAME is empty."); }

    listElement* element = start;

    while (element != nullptr) 
    {
        if (element->data.getName() == name) { return element->data.getPhoneNumber(); }
        element = element->next;
    }

    throw NoSuchElementException("NAME not found.");
}

string Model::Phonebook::FindPhone(int id) const 
{
    if (id < 0) { throw WrongInputException("ID not in correct range."); }

    listElement* newElement = start;

    while (newElement != nullptr) 
    {
        if (newElement->data.getId() == id) { return newElement->data.getPhoneNumber(); }
        newElement = newElement->next;
    }

    throw NoSuchElementException("ID not found.");
}

Model::Phonebook::Phonebook() {}

Model::Phonebook::~Phonebook() 
{
    listElement* newElement = new listElement{};

    while (newElement != nullptr) 
    {
        listElement* tmp = newElement->next;
        delete newElement;
        newElement = tmp;
    }
}
