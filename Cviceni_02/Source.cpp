#include "Uctenka.h"
#include "Pokladna.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	Uctenka* uctenka1 = new Uctenka();
	uctenka1->setCisloUctenky(1);
	uctenka1->setCastka(10);
	uctenka1->setDPH(2);

	cout << uctenka1->getCisloUctenky() << "\n";
	cout << uctenka1->getCastka() << "\n";
	cout << uctenka1->getDPH() << "\n";

	delete uctenka1;
	// ----------------------------------------
	cout << "\n";
	cout << "\n";

	Pokladna* pokladna1 = new Pokladna();
	Uctenka uctenkaP1 = pokladna1->vystavUctenku(100.2, 0.21);
	cout << pokladna1->getUctenku(uctenkaP1.getCisloUctenky()).getCastka() << "\n";
	cout << pokladna1->getUctenku(uctenkaP1.getCisloUctenky()).getDPH() << "\n";
	cout << pokladna1->getCastku() << "\n";
	cout << pokladna1->getCastkuVcDph() << "\n";
	cout << "\n";

	Uctenka uctenkaP2 =  pokladna1->vystavUctenku(150.3, 0.10);
	cout << pokladna1->getUctenku(uctenkaP2.getCisloUctenky()).getCastka() << "\n";
	cout << pokladna1->getUctenku(uctenkaP2.getCisloUctenky()).getDPH() << "\n";
	cout << pokladna1->getCastku() << "\n";
	cout << pokladna1->getCastkuVcDph() << "\n";
	cout << "\n";

	Uctenka uctenkaP3 = pokladna1->vystavUctenku(250.5, 0.05);
	cout << pokladna1->getUctenku(uctenkaP3.getCisloUctenky()).getCastka() << "\n";
	cout << pokladna1->getUctenku(uctenkaP3.getCisloUctenky()).getDPH() << "\n";
	cout << pokladna1->getCastku() << "\n";
	cout << pokladna1->getCastkuVcDph() << "\n";
	cout << "\n";

	/*pokladna1->vystavUctenku(100, 21);
	pokladna1->vystavUctenku(100, 21);
	pokladna1->vystavUctenku(100, 21);
	pokladna1->vystavUctenku(100, 21);
	pokladna1->vystavUctenku(100, 21);
	pokladna1->vystavUctenku(100, 21);
	pokladna1->vystavUctenku(100, 21);
	pokladna1->vystavUctenku(100, 21);*/
	
	delete pokladna1;
	return 0;
}