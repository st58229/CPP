#include "Address.h"
#include "Date.h"
#include "Person.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


void saveFile() 
{
	Person field[3];

	field[0] = Person("Name1", "Sur1", Address("Ulice1", "Mesto1", 11111), Date(1, 1, 1111));
	field[1] = Person("Name2", "Sur2", Address("Ulice2", "Mesto2", 22222), Date(2, 2, 2222));
	field[2] = Person("Name3", "Sur3", Address("Ulice3", "Mesto3", 33333), Date(3, 3, 3333));

	ofstream fl{};
	fl.open("out.txt");

	if		(fl.is_open()) for (int i = 0; i < (sizeof(field)/sizeof(Person)); i++) fl << field[i];		
	else	cout << "File write error!" << endl;
	
	fl.close();
}

void loadFile() 
{
	int size = 0;
	string line;
	ifstream fl{};

	ifstream read("out.txt");
	while (getline(read, line)) size++;	
	read.close();

	Person* field = new Person[size];
	fl.open("out.txt");

	if (fl.is_open()) 
	{
		for (int i = 0; i < size; i++) 
		{
			Person p;
			fl >> p;
			field[i] = p;
			cout << field[i];
		}
	}
	else cout << "File load error!" << endl;
	
	delete[] field;
	fl.close();
}

void saveBinaryFile()
{
	Person field[3];

	field[0] = Person("Name1", "Sur1", Address("Ulice1", "Mesto1", 11111), Date(1, 1, 1111));
	field[1] = Person("Name2", "Sur2", Address("Ulice2", "Mesto2", 22222), Date(2, 2, 2222));
	field[2] = Person("Name3", "Sur3", Address("Ulice3", "Mesto3", 33333), Date(3, 3, 3333));

	ofstream fl{};
	fl.open("out.bin", ios_base::binary);

	if		(fl.is_open()) for (int i = 0; i < (sizeof(field) / sizeof(Person)); i++) fl.write((char*)&field[i], sizeof(Person));	
	else	cout << "File write error!" << endl;

	fl.close();
}

void loadBinaryFile()
{
	ifstream fl{};
	fl.open("out.bin", ios_base::binary);
	fl.seekg(0, ios::end);
	int size = fl.tellg() / sizeof(Person);
	Person* field = new Person[size]; 
	fl.seekg(0);

	if (fl.is_open()) 
	{
		for (int i = 0; i < size; i++)
		{
			fl.read((char*)&field[i], sizeof(Person));
			cout << field[i] << endl;
		}		
	}
	else 	cerr << "File load error!" << endl;

	fl.close();
}

int main(int argc, char** argv) {

	saveFile();
	loadFile();

	cout << "---------------------\n";

	saveBinaryFile();
	loadBinaryFile();

	system("pause");
	return 0;
}
