#include "Transaction.h"

Transaction::Transaction(
    int i,
    int f,
    double a,
    std::string d,
    std::string t)
{
    id = i;
    fineId = f;
    amount = a;
    date = d;
    type = t;
}

int Transaction::getId() const
{
    return id;
}

int Transaction::getFineId() const
{
    return fineId;
}

double Transaction::getAmount() const
{
    return amount;
}

std::string Transaction::getDate() const
{
    return date;
}

std::string Transaction::getType() const
{
    return type;
}
