#include "InputValidator.h"

bool InputValidator::isPositiveNumber(int value)
{
    return value > 0;
}

bool InputValidator::isNonNegativeNumber(double value)
{
    return value >= 0;
}

bool InputValidator::isNotEmpty(string value)
{
    return !value.empty();
}
