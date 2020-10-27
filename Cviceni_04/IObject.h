#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H
#include <string>
#include <iostream>

class IObject {
public:
	virtual ~IObject() {};
	virtual std::string toString() const = 0;
};

#endif