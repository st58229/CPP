#include "cui.h"
#include <iostream>
#include <fstream>
#include <iostream>

cui::cui()
{

}

cui::~cui()
{
    
}

void cui::show()
{
    for (int i = 0; i < listStudents.getSize(); i++)
    {      
       ObjectValue* item = dynamic_cast<ObjectValue*>(listStudents.get(i));

       std::string out;
       out.append(std::to_string(i)); //Id v poli pro mazání a tak
       out.append(" Name: ");
       out.append(dynamic_cast<StringValue*>(item->get(0).getValue())->get()); 
       out.append(" Surname: ");
       out.append(dynamic_cast<StringValue*>(item->get(1).getValue())->get());
       out.append(" Id: ");       
       out.append(std::to_string( dynamic_cast<NumberValue*>(item->get(2).getValue())->get()) );
       out.append(" Sex: ");
       out.append(dynamic_cast<StringValue*>(item->get(3).getValue())->get());
       out.append(" Birth: ");
       out.append(dynamic_cast<StringValue*>(item->get(4).getValue())->get());
       out.append(" Subjects: ");
       out.append(dynamic_cast<ArrayValue*>(item->get(5).getValue())->serialize());
       out.append(" Study: ");
       out.append(std::to_string( dynamic_cast<BoolValue*>(item->get(6).getValue())->get()) );
       out.append(" Year: ");
       out.append(std::to_string( dynamic_cast<NumberValue*>(item->get(7).getValue())->get()) );

       std::cout << out << std::endl;
    }    
}

void cui::showDetail(int index)
{

}

void cui::remove()
{
    std::cout << "Want to see list again? (y - yes):" << std::endl;
    std::string choice;
    std::cin >> choice;
    if (choice == "y")
    {
        show();
    }
    std::cout << "Insert index (number of begin) of student for delete:" << std::endl;
    int index;
    std::cin >> index;

    listStudents.remove(index);
    std::cout << "Removed. " << std::endl;
}

void cui::update()
{
    std::cout << "Want to see list again? (y - yes):" << std::endl;
    std::string choice;
    std::cin >> choice;
    if (choice == "y")
    {
        show();
    }

    Student* s = new Student();

    std::cout << "Insert index (number of begin) of student to update:" << std::endl;
    int index;
    std::cin >> index;

    s->createStudent(dynamic_cast<ObjectValue*>(listStudents.get(index)));
   
    std::cout << "Want to update Name? (y - yes):" << std::endl;
    std::cin >> choice;
    if (choice == "y")
    {        
        std::string firstname;
        std::cout << "Firstname: ";
        std::cin >> firstname;
        s->setJmeno(firstname);
    }

    std::cout << "Want to update Surname? (y - yes):" << std::endl;
    std::cin >> choice;
    if (choice == "y")
    {
        std::string lastname;
        std::cout << "Lastname: ";
        std::cin >> lastname;
        s->setPrijmeni(lastname);
    }

    std::cout << "Want to update Id? (y - yes):" << std::endl;
    std::cin >> choice;
    if (choice == "y")
    {
        int id;
        std::cout << "Id: ";
        std::cin >> id;
        s->setID(id);
    }

    std::cout << "Want to update Sex? (y - yes):" << std::endl;
    std::cin >> choice;
    if (choice == "y")
    {
        std::string sex;
        std::cout << "Sex: ";
        std::cin >> sex;
        s->setPohlavi(sex);
    }

    std::cout << "Want to update Birthdate? (y - yes):" << std::endl;
    std::cin >> choice;
    if (choice == "y")
    {
        std::string birthdate;
        std::cout << "Birthdate: ";
        std::cin >> birthdate;
        s->setdatumNarozeni(birthdate);
    }

    std::cout << "Want to update Subject? (y - yes):" << std::endl;
    std::cin >> choice;
    if (choice == "y")
    {
        ArrayValue* subjects = new ArrayValue{};
        std::string input;
        while (input != "e") {
            std::cout << "Add subject (e to exit): ";
            std::cin >> input;
            if (input != "e")  subjects->append(new StringValue(input));
        }
        s->setPredmety(subjects);
    }

    std::cout << "Want to update Study? (y - yes):" << std::endl;
    std::cin >> choice;
    if (choice == "y")
    {
        std::string activeString;
        bool active;
        while (activeString != "t" && activeString != "f") {
            std::cout << "Active (t - true, f - false): ";
            std::cin >> activeString;
        }
        if (activeString == "t") active = true;
        else active = false;
        s->setStuduje(active);
    }

    std::cout << "Want to update Year? (y - yes):" << std::endl;
    std::cin >> choice;
    if (choice == "y")
    {
        int studyYear;
        std::cout << "Study year: ";
        std::cin >> studyYear;
        s->setRocnik(studyYear);
    }

    listStudents.remove(index);
    listStudents.append(s->toValue());

    std::cout << "Updated. " << std::endl;

}

void cui::printFile(std::string string)
{
    std::ofstream fl{};
    fl.open("out.txt");

    if (fl.is_open())
    {
        fl << string;
    }        
    else
    {
        std::cout << "File write error!" << std::endl;
        return;
    }

    fl.close();

    std::cout << "Saved." << std::endl;
}

void cui::readFile()
{
    std::ifstream fl{};
    
    fl.open("out.txt");

    std::string value;

    ArrayValue* fromFile;

    if (fl.fail())
    {
        std::cout << "File load error!" << std::endl;
        fl.close();
        return;
    }

    fl >> value;

    fromFile = dynamic_cast<ArrayValue*> (JSON::deserialize(value));      
    
    for (int i = 0; i < fromFile->getSize(); i++)
    {
        listStudents.append(dynamic_cast<ObjectValue*>(fromFile->get(i)));
    }
   
    fl.close();

    std::cout << "Loaded." << std::endl;
}

void cui::add() {
    Student* s = new Student();
    std::string firstname;
    std::cout << "Firstname: ";
    std::cin >> firstname;
    s->setJmeno(firstname);

    std::string lastname;
    std::cout << "Lastname: ";
    std::cin >> lastname;
    s->setPrijmeni(lastname);

    int id;
    std::cout << "Id: ";
    std::cin >> id;
    s->setID(id);

    std::string sex;
    std::cout << "Sex: ";
    std::cin >> sex;
    s->setPohlavi(sex);

    std::string birthdate;
    std::cout << "Birthdate: ";
    std::cin >> birthdate;
    s->setdatumNarozeni(birthdate);

    ArrayValue* subjects = new ArrayValue{};    
    std::string input;
    while (input != "e") {
        std::cout << "Add subject (e to exit): ";
        std::cin >> input;
        if (input != "e")  subjects->append(new StringValue(input));
    }
    s->setPredmety(subjects);

    std::string activeString;
    bool active;
    while (activeString != "t" && activeString != "f") {
        std::cout << "Active (t - true, f - false): ";
        std::cin >> activeString;
    }

    if (activeString == "t") active = true;
    else active = false;
    s->setStuduje(active);

    int studyYear;
    std::cout << "Study year: ";
    std::cin >> studyYear;
    s->setRocnik(studyYear);

    listStudents.append(s->toValue());
    std::cout << "Added. " << std::endl;
}

void cui::menu()
{
    std::cout << "Select:" << std::endl;
    std::cout << "1 - add student" << std::endl;
    std::cout << "2 - delete student" << std::endl;
    std::cout << "3 - edit student" << std::endl;
    std::cout << "4 - print all" << std::endl;
    std::cout << "5 - write to JSON" << std::endl;
    std::cout << "6 - read from JSON" << std::endl;
    std::cout << "0 - exit" << std::endl;

    std::cin >> selected;
}

void cui::callChoice()
{
    do {
        switch (selected) {
        case 1:            
            add();
            selected = -1;
            break;
        case 2:
            remove();
            selected = -1;
            break;
        case 3:
            update();
            selected = -1;
            break;
        case 4:
            show();            
            selected = -1;
            break;
        case 5:            
            printFile(listStudents.serialize());
            selected = -1;
            break;
        case 6: 
            std::cin.ignore();
            readFile(); 
            selected = -1;
            break;
        default:
            menu();            
            break;
        }
    } while (selected != 0);
}

    