#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
#include <iostream>

class InputValidator
{
public:
    static bool isPositiveNumber(int value);
    static bool isNonNegativeNumber(double value);
    static bool isNotEmpty(std::string value);
    static bool isValidEmail(std::string email);
    static bool isValidPhone(std::string phone);

    static bool readPositiveInt(int &value);
    static bool readNonNegativeInt(int &value);
    static bool readNonNegativeDouble(double &value);
};

#endif // INPUTVALIDATOR_H
