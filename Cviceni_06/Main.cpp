#include "IncreasingContainer.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	IncreasingContainer <string, 5> container = IncreasingContainer<string, 5>();

	for (size_t i = 0; i < 15; i++)
	{
		container.add(to_string(i));
		cout << container[i] << endl;
	}
	cout << "(15) Pocet: "  << container.getItemsLenght() << endl;
	cout << endl;

	cout << "Odeberu indexy 1 a 14" << endl;
	container.remove(14);
	container.remove(1);
	for (size_t i = 0; i < container.getItemsLenght(); i++)
	{
		cout << container[i] << endl;
	}
	cout << "(13) Pocet: " << container.getItemsLenght() << endl;
	cout << endl;

	cout << "Na index 1 pridavam -15-, na index 14 pridavam -16-" << endl;
	container.add(1, to_string(15));
	container.add(14, to_string(16));
	for (size_t i = 0; i < container.getItemsLenght(); i++)
	{
		cout << container[i] << endl;
	}
	cout << "(15) Pocet: " << container.getItemsLenght() << endl;


	return 0;
}