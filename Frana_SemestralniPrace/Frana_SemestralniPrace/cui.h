#pragma once

#include "Student.h"

class cui
{

private:

	ArrayValue listStudents;	
	int selected;

public:

	cui();
	~cui();

	void show();
	void showDetail(int index); //Asi, podle ne�eho hledat v poli studenty

	void add(); //Vyvol� konzol dialog, vytvo�� srtudenta, vlo�� do pole

	void remove(); //Vyvol� dialog, kde se zept� na index a pak poijede

	void update(); //Vyvol� dialog, kde se zept� na index a pak poijede

	void menu();

	void callChoice();

	void printFile(std::string string);

	void readFile();

};

