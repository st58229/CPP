#include <stdio.h>
#include <iostream>

using namespace std;

struct Trojuhelnik
{
	int a;
	int b;
	int c;
	int obvod;
};

bool lzeSestrojit(Trojuhelnik t) 
{
	return (t.a + t.b) > t.c && (t.a + t.c) > t.b && (t.c + t.b) > t.a;
}

bool lzeSestrojit(Trojuhelnik* t)
{
	return (t->a + t->b) > t->c && (t->a + t->c) > t->b && (t->c + t->b) > t->a;
}

void vypocetObvodu(Trojuhelnik t) 
{
	t.obvod = t.a + t.b + t.c;
}

void vypocetObvodu(Trojuhelnik* t)
{
	t->obvod = t->a + t->b + t->c;
}

int main(int argc, char** argv) 
{
	int pocet;
	while (true) 
	{
		cout << "Zadejte pocet trojuhelniku\t";	
		cin >> pocet;
		if (isdigit)
		{
			break;
		}
	}

	Trojuhelnik* pole = new Trojuhelnik[pocet];
	Trojuhelnik* ukazatel = new Trojuhelnik;

	int i = 0;
	while (i < pocet)
	{		
		cout << "Zadejte velikost strany A\t";
		cin >> ukazatel->a;
		cout << "Zadejte velikost strany B\t";
		cin >> ukazatel->b;
		cout << "Zadejte velikost strany C\t";
		cin >> ukazatel->c;

		if (lzeSestrojit(ukazatel))
		{
			vypocetObvodu(ukazatel);

			cout << "Obvod trojuhelniku je:\t\t" << ukazatel->obvod << "\n\n";
			pole[i].a = ukazatel->a;
			pole[i].b = ukazatel->b;
			pole[i].c = ukazatel->c;
			pole[i].obvod = ukazatel->obvod;
			i++;
		}
		else cout << "Neplatny trojuhelnik.\n";

	}	

	int obvody = 0;
	for (int i = 0; i < pocet; i++)
	{		
		obvody += pole[i].obvod;
	}

	cout << "Soucet obvodu trojuhelniku je:" << obvody << " .\n";

	delete   ukazatel;
	delete[] pole;
	system("pause");
	return 0;

}