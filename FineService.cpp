#include "FineService.h"
#include <iostream>

using namespace std;

void FineService::addFine()
{
    int id;
    int borrowingId;
    double amount;
    string fineDate;

    cout << "\n===== Add Fine =====" << endl;

    cout << "Enter Fine ID: ";
    cin >> id;

    cout << "Enter Borrowing ID: ";
    cin >> borrowingId;

    cout << "Enter Fine Amount: ";
    cin >> amount;

    if (amount < 0)
    {
        cout << "Fine amount cannot be negative!" << endl;
        return;
    }

    cout << "Enter Fine Date: ";
    cin >> fineDate;

    fines.push_back(Fine(id, borrowingId, amount, fineDate, false));

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
    int id;

    cout << "\n===== Search Fine =====" << endl;
    cout << "Enter Fine ID: ";
    cin >> id;

    for (Fine fine : fines)
    {
        if (fine.id == id)
        {
            cout << "Fine found!" << endl;
            cout << "Borrowing ID: " << fine.borrowingId << endl;
            cout << "Amount: " << fine.amount << endl;
            cout << "Fine Date: " << fine.fineDate << endl;
            cout << "Paid: " << (fine.paid ? "Yes" : "No") << endl;
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
    cin >> id;

    for (Fine &fine : fines)
    {
        if (fine.id == id)
        {
            cout << "Enter new amount: ";
            cin >> fine.amount;

            if (fine.amount < 0)
            {
                cout << "Fine amount cannot be negative!" << endl;
                return;
            }

            cout << "Enter new date: ";
            cin >> fine.fineDate;

            cout << "Fine updated successfully!" << endl;
            return;
        }
    }

    cout << "Fine not found!" << endl;
}

void FineService::deleteFine()
{
    int id;

    cout << "\n===== Delete Fine =====" << endl;
    cout << "Enter Fine ID: ";
    cin >> id;

    for (auto it = fines.begin(); it != fines.end(); ++it)
    {
        if (it->id == id)
        {
            fines.erase(it);
            cout << "Fine deleted successfully!" << endl;
            return;
        }
    }

    cout << "Fine not found!" << endl;
}

void FineService::payFine()
{
    int id;

    cout << "\n===== Pay Fine =====" << endl;
    cout << "Enter Fine ID: ";
    cin >> id;

    for (Fine &fine : fines)
    {
        if (fine.id == id)
        {
            fine.paid = true;
            cout << "Fine paid successfully!" << endl;
            return;
        }
    }

    cout << "Fine not found!" << endl;
}
