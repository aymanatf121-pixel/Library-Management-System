#ifndef ACCOUNTINGSERVICE_H
#define ACCOUNTINGSERVICE_H

#include "Transaction.h"
#include <vector>

using namespace std;

class AccountingService
{
private:
    vector<Transaction> transactions;

public:
    void addTransaction(int fineId, double amount, string date);
    void viewTransactions();
    void viewRevenueReport();
};

#endif // ACCOUNTINGSERVICE_H
