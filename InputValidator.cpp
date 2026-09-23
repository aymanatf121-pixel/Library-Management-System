#include "InputValidator.h"
#include <limits>

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
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
        return false;
    }

    if (!isPositiveNumber(value))
    {
        return false;
    }

    return true;
}

bool InputValidator::readNonNegativeInt(int &value)
{
    if (!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
        return false;
    }

    if (value < 0)
    {
        return false;
    }

    return true;
}

bool InputValidator::readNonNegativeDouble(double &value)
{
    if (!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
        return false;
    }

    if (!isNonNegativeNumber(value))
    {
        return false;
    }

    return true;
}
