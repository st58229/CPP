#include "Exceptions.h"

Exceptions::Exceptions(std::string message) : message(message) {}

std::string Exceptions::getMessage() { return message; }