#include "Fine.h"

Fine::Fine(
    int i,
    int b,
    double a,
    std::string d,
    bool p)
{
    id = i;
    borrowingId = b;
    amount = a;
    fineDate = d;
    paid = p;
}

int Fine::getId() const
{
    return id;
}

int Fine::getBorrowingId() const
{
    return borrowingId;
}

double Fine::getAmount() const
{
    return amount;
}

std::string Fine::getFineDate() const
{
    return fineDate;
}

bool Fine::isPaid() const
{
    return paid;
}

void Fine::setAmount(double a)
{
    amount = a;
}

void Fine::setFineDate(std::string d)
{
    fineDate = d;
}

void Fine::setPaid(bool p)
{
    paid = p;
}
