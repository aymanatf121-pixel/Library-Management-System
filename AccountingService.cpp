#include "AccountingService.h"
#include <iostream>

using namespace std;

void AccountingService::addTransaction(int fineId, double amount, string date)
{
    int id = transactions.size() + 1;

    Transaction transaction(
        id,
        fineId,
        amount,
        date,
        "Fine Payment"
    );

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
        cout << "Transaction ID: " << transaction.getId() << endl;
        cout << "Fine ID: " << transaction.getFineId() << endl;
        cout << "Amount: " << transaction.getAmount() << endl;
        cout << "Date: " << transaction.getDate() << endl;
        cout << "Type: " << transaction.getType() << endl;
        cout << "------------------------" << endl;
    }
}

void AccountingService::viewRevenueReport()
{
    double totalRevenue = 0;

    for (Transaction transaction : transactions)
    {
        totalRevenue += transaction.getAmount();
    }

    cout << "\n===== Revenue Report =====" << endl;
    cout << "Transaction Count: " << transactions.size() << endl;
    cout << "Total Revenue: " << totalRevenue << endl;
}

std::vector<Transaction>& AccountingService::getAllTransactions()
{
    return transactions;
}
