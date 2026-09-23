#include "FineService.h"
#include "InputValidator.h"
#include <iostream>
#include <string>

using namespace std;

void FineService::addFine(BorrowingService &borrowingService)
{
    int borrowingId;
    double amount;
    string fineDate;

    cout << "\n===== Add Fine =====" << endl;

    cout << "Enter Borrowing ID: ";

    if (!InputValidator::readPositiveInt(borrowingId))
    {
        cout << "Invalid Borrowing ID!" << endl;
        return;
    }

    if (!borrowingService.borrowingExists(borrowingId))
    {
        cout << "Borrowing not found!" << endl;
        return;
    }

    cout << "Enter Fine Amount: ";

    if (!InputValidator::readNonNegativeDouble(amount))
    {
        cout << "Invalid Fine Amount!" << endl;
        return;
    }

    cout << "Enter Fine Date: ";
    cin >> fineDate;

    if (!InputValidator::isNotEmpty(fineDate))
    {
        cout << "Fine date cannot be empty!" << endl;
        return;
    }

    int id = fines.size() + 1;

    Fine fine(
        id,
        borrowingId,
        amount,
        fineDate,
        false
    );

    fines.push_back(fine);

    cout << "Fine added successfully!" << endl;
}

void FineService::viewFines()
{
    cout << "\n===== Fines List =====" << endl;

    if (fines.empty())
    {
        cout << "No fines available." << endl;
        return;
    }

    for (Fine fine : fines)
    {
        cout << "Fine ID: " << fine.getId() << endl;
        cout << "Borrowing ID: " << fine.getBorrowingId() << endl;
        cout << "Amount: " << fine.getAmount() << endl;
        cout << "Fine Date: " << fine.getFineDate() << endl;
        cout << "Paid: " << (fine.isPaid() ? "Yes" : "No") << endl;
        cout << "------------------------" << endl;
    }
}

void FineService::searchFine()
{
    int id;

    cout << "\n===== Search Fine =====" << endl;

    cout << "Enter Fine ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Fine ID!" << endl;
        return;
    }

    for (Fine &fine : fines)
    {
        if (fine.getId() == id)
        {
            cout << "Fine found!" << endl;
            cout << "Borrowing ID: " << fine.getBorrowingId() << endl;
            cout << "Amount: " << fine.getAmount() << endl;
            cout << "Fine Date: " << fine.getFineDate() << endl;
            cout << "Paid: " << (fine.isPaid() ? "Yes" : "No") << endl;
            return;
        }
    }

    cout << "Fine not found!" << endl;
}

void FineService::updateFine()
{
    int id;

    cout << "\n===== Update Fine =====" << endl;

    cout << "Enter Fine ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Fine ID!" << endl;
        return;
    }

    Fine* fine = nullptr;

    for (Fine &item : fines)
    {
        if (item.getId() == id)
        {
            fine = &item;
            break;
        }
    }

    if (fine == nullptr)
    {
        cout << "Fine not found!" << endl;
        return;
    }

    double newAmount;
    string newDate;

    cout << "Enter new Fine Amount: ";

    if (!InputValidator::readNonNegativeDouble(newAmount))
    {
        cout << "Invalid Fine Amount!" << endl;
        return;
    }

    cout << "Enter new Fine Date: ";
    cin >> newDate;

    if (!InputValidator::isNotEmpty(newDate))
    {
        cout << "Fine date cannot be empty!" << endl;
        return;
    }

    fine->setAmount(newAmount);
    fine->setFineDate(newDate);

    cout << "Fine updated successfully!" << endl;
}

void FineService::deleteFine()
{
    int id;

    cout << "\n===== Delete Fine =====" << endl;

    cout << "Enter Fine ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Fine ID!" << endl;
        return;
    }

    for (auto it = fines.begin(); it != fines.end(); ++it)
    {
        if (it->getId() == id)
        {
            fines.erase(it);
            cout << "Fine deleted successfully!" << endl;
            return;
        }
    }

    cout << "Fine not found!" << endl;
}

void FineService::payFine(AccountingService &accountingService)
{
    int id;
    string paymentDate;

    cout << "\n===== Pay Fine =====" << endl;

    cout << "Enter Fine ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Fine ID!" << endl;
        return;
    }

    Fine* fine = nullptr;

    for (Fine &item : fines)
    {
        if (item.getId() == id)
        {
            fine = &item;
            break;
        }
    }

    if (fine == nullptr)
    {
        cout << "Fine not found!" << endl;
        return;
    }

    if (fine->isPaid())
    {
        cout << "Fine has already been paid!" << endl;
        return;
    }

    cout << "Enter Payment Date: ";
    cin >> paymentDate;

    if (!InputValidator::isNotEmpty(paymentDate))
    {
        cout << "Payment date cannot be empty!" << endl;
        return;
    }

    accountingService.addTransaction(
        fine->getId(),
        fine->getAmount(),
        paymentDate
    );

    fine->setPaid(true);

    cout << "Fine paid successfully!" << endl;
}
