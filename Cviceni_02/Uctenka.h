#pragma once
#ifndef UCTENKA_H
#define UCTENKA_H
class Uctenka
{
	private:
		int cisloUctenky;
		double castka;
		double dph;

	public:
		void	setCisloUctenky(int cisloUctenky);
		int		getCisloUctenky() const;
		void	setCastka(double castka);
		double  getCastka() const;
		void	setDPH(double dph);
		double  getDPH() const;
};

#endif