#include "FineService.h"
#include "InputValidator.h"
#include <iostream>
#include <string>

using namespace std;

void FineService::addFine(BorrowingService &borrowingService)
{
    int id = 0;
    int borrowingId = 0;
    double amount = 0;
    string fineDate;

    cout << "\n===== Add Fine =====" << endl;

    cout << "Enter Fine ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Fine ID!" << endl;
        return;
    }

    if (fineRepository.findFine(id) != nullptr)
    {
        cout << "Fine ID already exists!" << endl;
        return;
    }

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

    fineRepository.addFine(
        Fine(id, borrowingId, amount, fineDate, false)
    );

    cout << "Fine added successfully!" << endl;
}

void FineService::viewFines()
{
    cout << "\n===== Fines List =====" << endl;

    if (fineRepository.getAllFines().empty())
    {
        cout << "No fines available." << endl;
        return;
    }

    for (Fine fine : fineRepository.getAllFines())
    {
        cout << "Fine ID: " << fine.id << endl;
        cout << "Borrowing ID: " << fine.borrowingId << endl;
        cout << "Amount: " << fine.amount << endl;
        cout << "Fine Date: " << fine.fineDate << endl;
        cout << "Paid: " << (fine.paid ? "Yes" : "No") << endl;
        cout << "------------------------" << endl;
    }
}

void FineService::searchFine()
{
    int id = 0;

    cout << "\n===== Search Fine =====" << endl;

    cout << "Enter Fine ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Fine ID!" << endl;
        return;
    }

    Fine* fine = fineRepository.findFine(id);

    if (fine != nullptr)
    {
        cout << "Fine found!" << endl;
        cout << "Borrowing ID: " << fine->borrowingId << endl;
        cout << "Amount: " << fine->amount << endl;
        cout << "Fine Date: " << fine->fineDate << endl;
        cout << "Paid: " << (fine->paid ? "Yes" : "No") << endl;
        return;
    }

    cout << "Fine not found!" << endl;
}

void FineService::updateFine()
{
    int id = 0;

    cout << "\n===== Update Fine =====" << endl;

    cout << "Enter Fine ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Fine ID!" << endl;
        return;
    }

    Fine* fine = fineRepository.findFine(id);

    if (fine == nullptr)
    {
        cout << "Fine not found!" << endl;
        return;
    }

    double newAmount;
    string newDate;

    cout << "Enter new amount: ";

    if (!InputValidator::readNonNegativeDouble(newAmount))
    {
        cout << "Invalid Fine Amount!" << endl;
        return;
    }

    cout << "Enter new date: ";
    cin >> newDate;

    if (!InputValidator::isNotEmpty(newDate))
    {
        cout << "Fine date cannot be empty!" << endl;
        return;
    }

    fine->amount = newAmount;
    fine->fineDate = newDate;

    cout << "Fine updated successfully!" << endl;
}

void FineService::deleteFine()
{
    int id = 0;

    cout << "\n===== Delete Fine =====" << endl;

    cout << "Enter Fine ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Fine ID!" << endl;
        return;
    }

    if (fineRepository.deleteFine(id))
    {
        cout << "Fine deleted successfully!" << endl;
        return;
    }

    cout << "Fine not found!" << endl;
}

void FineService::payFine(AccountingService &accountingService)
{
    int id = 0;

    cout << "\n===== Pay Fine =====" << endl;

    cout << "Enter Fine ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Fine ID!" << endl;
        return;
    }

    Fine* fine = fineRepository.findFine(id);

    if (fine == nullptr)
    {
        cout << "Fine not found!" << endl;
        return;
    }

    if (fine->paid)
    {
        cout << "Fine has already been paid!" << endl;
        return;
    }

    string paymentDate;

    cout << "Enter Payment Date: ";
    cin >> paymentDate;

    if (!InputValidator::isNotEmpty(paymentDate))
    {
        cout << "Payment date cannot be empty!" << endl;
        return;
    }

    fine->paid = true;

    accountingService.addTransaction(
        fine->id,
        fine->amount,
        paymentDate
    );

    cout << "Fine paid successfully!" << endl;
}
