#include "BorrowingService.h"
#include "InputValidator.h"
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

    if (!InputValidator::isPositiveNumber(id))
    {
        cout << "Borrowing ID must be positive!" << endl;
        return;
    }

    cout << "Enter Member ID: ";
    cin >> memberId;

    if (!InputValidator::isPositiveNumber(memberId))
    {
        cout << "Member ID must be positive!" << endl;
        return;
    }

    if (!memberService.memberExists(memberId))
    {
        cout << "Member not found!" << endl;
        return;
    }

    cout << "Enter Book ID: ";
    cin >> bookId;

    if (!InputValidator::isPositiveNumber(bookId))
    {
        cout << "Book ID must be positive!" << endl;
        return;
    }

    if (!bookService.bookExists(bookId))
    {
        cout << "Book not found!" << endl;
        return;
    }

    if (!bookService.decreaseQuantity(bookId))
    {
        cout << "Book is not available!" << endl;
        return;
    }

    cout << "Enter Borrow Date: ";
    cin >> borrowDate;

    if (!InputValidator::isNotEmpty(borrowDate))
    {
        cout << "Borrow date cannot be empty!" << endl;
        bookService.increaseQuantity(bookId);
        return;
    }

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
    int borrowingId;

    cout << "\n===== Return Book =====" << endl;
    cout << "Enter Borrowing ID: ";
    cin >> borrowingId;

    if (!InputValidator::isPositiveNumber(borrowingId))
    {
        cout << "Borrowing ID must be positive!" << endl;
        return;
    }

    for (Borrowing &borrowing : borrowings)
    {
        if (borrowing.id == borrowingId)
        {
            if (borrowing.status == "Returned")
            {
                cout << "Book has already been returned!" << endl;
                return;
            }

            borrowing.status = "Returned";

            cout << "Enter Return Date: ";
            cin >> borrowing.returnDate;

            if (!InputValidator::isNotEmpty(borrowing.returnDate))
            {
                cout << "Return date cannot be empty!" << endl;
                return;
            }

            bookService.increaseQuantity(borrowing.bookId);

            cout << "Book returned successfully!" << endl;
            return;
        }
    }

    cout << "Borrowing not found!" << endl;
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
