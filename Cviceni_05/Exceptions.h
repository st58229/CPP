#pragma once
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

using namespace std;
struct Exceptions 
{
private:
    string message;
public:
    Exceptions(string message);
    virtual string getMessage();
};

struct NoSuchElementException : Exceptions { NoSuchElementException(string message) : Exceptions(message) {} };

struct WrongInputException : Exceptions { WrongInputException(string message) : Exceptions(message) {} };

#endif