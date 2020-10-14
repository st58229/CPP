#include "Pokladna.h"
#include <execution>
#include <iostream>
#include <stdexcept>

#define CITAC_ID_HODNOTA 1000

Pokladna::Pokladna() 
{
	uctenky = new Uctenka[10];	
	citac = 0;
}
Pokladna::~Pokladna() 
{
	delete[] uctenky;
}
Uctenka& Pokladna::vystavUctenku(double castka, double dph)
{
	if (citac < 10)
	{		
		uctenky[citac].setCisloUctenky(citac + CITAC_ID_HODNOTA);
		uctenky[citac].setCastka(castka);
		uctenky[citac].setDPH(dph);
		citac++;
		return uctenky[citac - 1];
	}
	else 
	{
		throw new std::exception("Prekrocen limit");
	}

}
Uctenka& Pokladna::getUctenku(int cisloUctenky)
{
	for (int i = 0; i < citac; i++)
	{
		if (uctenky[i].getCisloUctenky() == cisloUctenky)
		{
			return uctenky[i];
		}
	}
	throw new std::exception("Nic tu neni.");	
}
double Pokladna::getCastku() const
{
	double soucet = 0;
	for (int i = 0; i < citac; i++)
	{
		soucet += uctenky[i].getCastka();
	}
	return soucet;
}
double Pokladna::getCastkuVcDph() const
{
	double soucet = 0;
	for (int i = 0; i < citac; i++)
	{
		//soucet += uctenky[i].getCastka();
		soucet += (uctenky[i].getCastka()*(1+uctenky[i].getDPH()));
	}
	return soucet;
}