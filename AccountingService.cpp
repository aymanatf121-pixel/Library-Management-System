#include "AccountingService.h"
#include <iostream>

using namespace std;

void AccountingService::addTransaction(int fineId, double amount, string date)
{
    int id = transactions.size() + 1;

    Transaction transaction(id, fineId, amount, date, "Fine Payment");

    transactions.push_back(transaction);

    cout << "Transaction added successfully!" << endl;
}
void AccountingService::viewTransactions()
{
    cout << "\n===== Transactions List =====" << endl;

    if (transactions.empty())
    {
        cout << "No transactions available." << endl;
        return;
    }

    for (Transaction transaction : transactions)
    {
        cout << "Transaction ID: " << transaction.id << endl;
        cout << "Fine ID: " << transaction.fineId << endl;
        cout << "Amount: " << transaction.amount << endl;
        cout << "Date: " << transaction.date << endl;
        cout << "Type: " << transaction.type << endl;
        cout << "------------------------" << endl;
    }
}
void AccountingService::viewRevenueReport()
{
    double totalRevenue = 0;

    for (Transaction transaction : transactions)
    {
        totalRevenue += transaction.amount;
    }

    cout << "\n===== Revenue Report =====" << endl;
    cout << "Transaction Count: " << transactions.size() << endl;
    cout << "Total Revenue: " << totalRevenue << endl;
}

