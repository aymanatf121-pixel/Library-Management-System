#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction
{
private:
    int id;
    int fineId;
    double amount;
    std::string date;
    std::string type;

public:
    Transaction(
        int i,
        int f,
        double a,
        std::string d,
        std::string t
    );

    int getId() const;
    int getFineId() const;
    double getAmount() const;
    std::string getDate() const;
    std::string getType() const;
};

#endif // TRANSACTION_H
