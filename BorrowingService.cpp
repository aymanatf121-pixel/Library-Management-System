#include "BorrowingService.h"
#include <iostream>

using namespace std;

void BorrowingService::borrowBook(BookService &bookService, MemberService &memberService)
{
    int id;
    int memberId;
    int bookId;
    string borrowDate;

    cout << "\n===== Borrow Book =====" << endl;

    cout << "Enter Borrowing ID: ";
    cin >> id;

    cout << "Enter Member ID: ";
    cin >> memberId;

    cout << "Enter Book ID: ";
    cin >> bookId;

    cout << "Enter Borrow Date: ";
    cin >> borrowDate;

    Borrowing borrowing(id, memberId, bookId, borrowDate, "", "Borrowed");

    borrowings.push_back(borrowing);

    cout << "Book borrowed successfully!" << endl;
}

void BorrowingService::viewBorrowings()
{
    cout << "\n===== Borrowing List =====" << endl;

    if (borrowings.empty())
    {
        cout << "No borrowing records available." << endl;
        return;
    }

    for (Borrowing borrowing : borrowings)
    {
        cout << "Borrowing ID: " << borrowing.id << endl;
        cout << "Member ID: " << borrowing.memberId << endl;
        cout << "Book ID: " << borrowing.bookId << endl;
        cout << "Borrow Date: " << borrowing.borrowDate << endl;
        cout << "Return Date: " << borrowing.returnDate << endl;
        cout << "Status: " << borrowing.status << endl;
        cout << "------------------------" << endl;
    }
}

void BorrowingService::returnBook(BookService &bookService)
{
    int id;
    string returnDate;

    cout << "\n===== Return Book =====" << endl;

    cout << "Enter Borrowing ID: ";
    cin >> id;

    for (Borrowing &borrowing : borrowings)
    {
        if (borrowing.id == id)
        {
            cout << "Enter Return Date: ";
            cin >> returnDate;

            borrowing.returnDate = returnDate;
            borrowing.status = "Returned";

            cout << "Book returned successfully!" << endl;
            return;
        }
    }

    cout << "Borrowing record not found!" << endl;
}

void BorrowingService::searchBorrowing()
{
    int id;

    cout << "\n===== Search Borrowing =====" << endl;
    cout << "Enter Borrowing ID: ";
    cin >> id;

    for (Borrowing borrowing : borrowings)
    {
        if (borrowing.id == id)
        {
            cout << "Borrowing found!" << endl;
            cout << "Member ID: " << borrowing.memberId << endl;
            cout << "Book ID: " << borrowing.bookId << endl;
            cout << "Borrow Date: " << borrowing.borrowDate << endl;
            cout << "Return Date: " << borrowing.returnDate << endl;
            cout << "Status: " << borrowing.status << endl;
            return;
        }
    }

    cout << "Borrowing record not found!" << endl;
}
