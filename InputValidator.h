#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>

using namespace std;

class InputValidator
{
public:
    static bool isPositiveNumber(int value);
    static bool isNonNegativeNumber(double value);
    static bool isNotEmpty(string value);
};

#endif // INPUTVALIDATOR_H
