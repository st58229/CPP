#include<iostream>
#include "Time.h"
#include "TimeOrder.h"


using namespace std;
int main() {

	int size = 7;
	Time* tm1 = new Time(24, 59, 59);
	Time* tm2 = new Time(00, 00, 01); 
	Time* tm3 = new Time(10, 12, 10);
	Time* tm4 = new Time(12, 10, 10);
	Time* tm5 = new Time(14, 10, 10);
	Time* tm6 = new Time(14, 12, 10);
	Time* tm7 = new Time(14, 12, 12);

	IComparable** field = new IComparable * [size];
	field[0] = tm1;
	field[1] = tm2;
	field[2] = tm3;
	field[3] = tm4;
	field[4] = tm5;
	field[5] = tm6;
	field[6] = tm7;


	for (size_t i = 0; i < size; i++)
	{
		cout << field[i]->toString() << endl;
	}

	cout << "============\n";

	TimeOrder::Order(field, size);

	for (size_t i = 0; i < size; i++)
	{
		cout << field[i]->toString() << endl;
	}

	delete[] field;

	system("pause");
	return 0;
}