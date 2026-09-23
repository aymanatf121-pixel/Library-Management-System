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

bool InputValidator::isValidEmail(std::string email)
{
    size_t atPosition = email.find('@');
    size_t dotPosition = email.find('.', atPosition);

    return atPosition != std::string::npos &&
           dotPosition != std::string::npos &&
           atPosition > 0 &&
           dotPosition > atPosition + 1 &&
           dotPosition < email.length() - 1;
}

bool InputValidator::isValidPhone(std::string phone)
{
    if (phone.length() != 11)
    {
        return false;
    }

    for (char digit : phone)
    {
        if (digit < '0' || digit > '9')
        {
            return false;
        }
    }

    return true;
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
