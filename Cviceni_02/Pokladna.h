#pragma once
#ifndef POKLADNA_H
#define POKLADNA_H

#include "Uctenka.h";

class Pokladna
{
	private:
		Uctenka* uctenka;		
		int citac;
		Uctenka* uctenky;

	public:
		Pokladna();
		~Pokladna();
		Uctenka& vystavUctenku(double castka, double dph);
		Uctenka& getUctenku(int cisloUctenky);
		double getCastku() const;
		double getCastkuVcDph() const;	 
};
#endif