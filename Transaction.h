#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction
{
public:
    int id;
    int fineId;
    double amount;
    string date;
    string type;

    Transaction(int i, int f, double a, string d, string t)
    {
        id = i;
        fineId = f;
        amount = a;
        date = d;
        type = t;
    }
};

#endif // TRANSACTION_H
