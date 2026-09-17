#include "InputValidator.h"

bool InputValidator::isPositiveNumber(int value)
{
    return value > 0;
}

bool InputValidator::isNonNegativeNumber(double value)
{
    return value >= 0;
}

bool InputValidator::isNotEmpty(std::string value)
{
    return !value.empty();
}

bool InputValidator::readPositiveInt(int &value)
{
    if (!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }

    return isPositiveNumber(value);
}

bool InputValidator::readNonNegativeInt(int &value)
{
    if (!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }

    return isNonNegativeNumber(value);
}

bool InputValidator::readNonNegativeDouble(double &value)
{
    if (!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }

    return isNonNegativeNumber(value);
}
