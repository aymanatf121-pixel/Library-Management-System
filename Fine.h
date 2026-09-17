#ifndef FINE_H
#define FINE_H

#include <string>


class Fine
{
public:
    int id;
    int borrowingId;
    double amount;
    std::string fineDate;
    bool paid;

    Fine(int i, int b, double a, std::string d, bool p)
    {
        id = i;
        borrowingId = b;
        amount = a;
        fineDate = d;
        paid = p;
    }
};

#endif // FINE_H
