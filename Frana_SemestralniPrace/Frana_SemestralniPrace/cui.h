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

	void add(); //Vyvol� konzol dialog, vytvo�� srtudenta, vlo�� do pole

	void remove(); //Vyvol� dialog, kde se zept� na index a pak poijede

	void update(); //Vyvol� dialog, kde se zept� na index a pak poijede

	void menu();

	void callChoice();

	void printFile(std::string string);

	void readFile();

};

