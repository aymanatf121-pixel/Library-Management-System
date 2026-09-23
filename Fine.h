#ifndef FINE_H
#define FINE_H

#include <string>

class Fine
{
private:
    int id;
    int borrowingId;
    double amount;
    std::string fineDate;
    bool paid;

public:
    Fine(
        int i,
        int b,
        double a,
        std::string d,
        bool p
    );

    int getId() const;
    int getBorrowingId() const;
    double getAmount() const;
    std::string getFineDate() const;
    bool isPaid() const;

    void setAmount(double a);
    void setFineDate(std::string d);
    void setPaid(bool p);
};

#endif // FINE_H
