#include "Uctenka.h"

void Uctenka::setCisloUctenky(int cisloUctenky) 
{
	this->cisloUctenky = cisloUctenky;
}
int  Uctenka::getCisloUctenky() const 
{
	return this->cisloUctenky;
}
void Uctenka::setCastka(double castka)
{
	this->castka = castka;
}
double  Uctenka::getCastka() const
{
	return this->castka;
}
void Uctenka::setDPH(double dph)
{
	this->dph = dph;
}
double  Uctenka::getDPH() const
{
	return this->dph;
}