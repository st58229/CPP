#pragma once

#include "Student.h"

class cui
{

private:

	ArrayValue* listStudents = new ArrayValue{};
	int selected;

public:

	cui();
	~cui();

	void show();
	void showDetail(int index); 

	void add(); //Vyvolá konzol dialog, vytvoøí srtudenta, vloží do pole

	void remove(); //Vyvolá dialog, kde se zeptá na index a pak poijede

	void update(); //Vyvolá dialog, kde se zeptá na index a pak poijede

	void menu();

	void callChoice();

	void printFile(std::string string);

	void readFile();

};

