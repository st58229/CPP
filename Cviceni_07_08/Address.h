#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>

struct Address {
private:
	std::string _street;
	std::string _city;
	int _postal;

public:
	Address();
	Address(std::string _street, std::string _city, int _postal);
	~Address();
	friend std::ostream& operator<<(std::ostream& read, const Address& data);
	friend std::istream& operator>>(std::istream& write, Address& data);
};

#endif


