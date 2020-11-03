#include<iostream>
#include "Exceptions.h"
#include "Person.h"
#include "Phonebook.h"

using namespace Entity;
using namespace Model;
using namespace std;

int main(int argc, char** argv) 
{
    try 
    {
        Phonebook list{};

        Person p1 = Person{ "Ing. Jan Husák", "+420 258 459 685", 0 };
        Person p2 = Person{ "Mudr. Ilona Konivková", "+420 787 485 985", 1 };
        Person p3 = Person{ "Jaromír Novák", "+420 758 596 158", 2 };
        Person p4 = Person{ "Jožko Laïoviè", "+421 901 224 210", 3 };

        list.addPerson(p1);
        list.addPerson(p2);
        list.addPerson(p3);
        list.addPerson(p4);

        cout << "(+420 258 459 685) " << list.FindPhone(0) << endl;
        cout << "(+420 787 485 985) " << list.FindPhone(1) << endl;
        cout << "(+420 758 596 158) " << list.FindPhone(2) << endl;
        cout << "(+421 901 224 210) " << list.FindPhone(3) << endl;
        cout << "(+421 901 224 210) " << list.FindPhone("Jožko Laïoviè") << endl;

        //list.FindPhone(5);
        //list.FindPhone("");
        list.FindPhone("test");

    }
    catch (WrongInputException& ex) 
    {
        cout << ex.getMessage() << endl;
    }
    catch (NoSuchElementException& ex) 
    {
        cout << ex.getMessage() << endl;
    }

    system("pause");
    return 0;
}