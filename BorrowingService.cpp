#include "BorrowingService.h"
#include "InputValidator.h"
#include <iostream>
#include <string>

using namespace std;

void BorrowingService::borrowBook(
    BookService &bookService,
    MemberService &memberService)
{
    int id;
    int memberId;
    int bookId;
    string borrowDate;

    cout << "\n===== Borrow Book =====" << endl;

    cout << "Enter Borrowing ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Borrowing ID!" << endl;
        return;
    }

    if (borrowingExists(id))
    {
        cout << "Borrowing ID already exists!" << endl;
        return;
    }

    cout << "Enter Member ID: ";

    if (!InputValidator::readPositiveInt(memberId))
    {
        cout << "Invalid Member ID!" << endl;
        return;
    }

    if (!memberService.memberExists(memberId))
    {
        cout << "Member not found!" << endl;
        return;
    }

    cout << "Enter Book ID: ";

    if (!InputValidator::readPositiveInt(bookId))
    {
        cout << "Invalid Book ID!" << endl;
        return;
    }

    if (!bookService.bookExists(bookId))
    {
        cout << "Book not found!" << endl;
        return;
    }

    // Prevent the same member from borrowing the same book twice
    // while the previous borrowing is still active.
    for (Borrowing &borrowing : borrowingRepository.getAllBorrowings())
    {
        if (borrowing.getMemberId() == memberId &&
            borrowing.getBookId() == bookId &&
            borrowing.getStatus() == "Borrowed")
        {
            cout << "This member has already borrowed this book!" << endl;
            return;
        }
    }

    if (!bookService.decreaseQuantity(bookId))
    {
        cout << "Book is not available!" << endl;
        return;
    }

    cout << "Enter Borrow Date (YYYY-MM-DD): ";
    cin >> borrowDate;

    if (!InputValidator::isValidDate(borrowDate))
    {
        cout << "Invalid borrow date! Use YYYY-MM-DD format." << endl;
        bookService.increaseQuantity(bookId);
        return;
    }

    Borrowing borrowing(
        id,
        memberId,
        bookId,
        borrowDate,
        "",
        "Borrowed"
    );

    borrowingRepository.addBorrowing(borrowing);

    cout << "Book borrowed successfully!" << endl;
}

void BorrowingService::viewBorrowings()
{
    cout << "\n===== Borrowings List =====" << endl;

    if (borrowingRepository.getAllBorrowings().empty())
    {
        cout << "No borrowings available." << endl;
        return;
    }

    for (Borrowing borrowing : borrowingRepository.getAllBorrowings())
    {
        cout << "Borrowing ID: " << borrowing.getId() << endl;
        cout << "Member ID: " << borrowing.getMemberId() << endl;
        cout << "Book ID: " << borrowing.getBookId() << endl;
        cout << "Borrow Date: " << borrowing.getBorrowDate() << endl;
        cout << "Return Date: " << borrowing.getReturnDate() << endl;
        cout << "Status: " << borrowing.getStatus() << endl;
        cout << "------------------------" << endl;
    }
}

void BorrowingService::returnBook(BookService &bookService)
{
    int id;

    cout << "\n===== Return Book =====" << endl;

    cout << "Enter Borrowing ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Borrowing ID!" << endl;
        return;
    }

    Borrowing* borrowing = borrowingRepository.findBorrowing(id);

    if (borrowing == nullptr)
    {
        cout << "Borrowing not found!" << endl;
        return;
    }

    if (borrowing->getStatus() == "Returned")
    {
        cout << "Book has already been returned!" << endl;
        return;
    }

    string returnDate;

    cout << "Enter Return Date (YYYY-MM-DD): ";
    cin >> returnDate;

    if (!InputValidator::isValidDate(returnDate))
    {
        cout << "Invalid return date! Use YYYY-MM-DD format." << endl;
        return;
    }

    borrowing->setReturnDate(returnDate);
    borrowing->setStatus("Returned");

    bookService.increaseQuantity(borrowing->getBookId());

    cout << "Book returned successfully!" << endl;
}

void BorrowingService::searchBorrowing()
{
    int id;

    cout << "\n===== Search Borrowing =====" << endl;

    cout << "Enter Borrowing ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Borrowing ID!" << endl;
        return;
    }

    Borrowing* borrowing = borrowingRepository.findBorrowing(id);

    if (borrowing != nullptr)
    {
        cout << "Borrowing found!" << endl;
        cout << "Member ID: " << borrowing->getMemberId() << endl;
        cout << "Book ID: " << borrowing->getBookId() << endl;
        cout << "Borrow Date: " << borrowing->getBorrowDate() << endl;
        cout << "Return Date: " << borrowing->getReturnDate() << endl;
        cout << "Status: " << borrowing->getStatus() << endl;
        return;
    }

    cout << "Borrowing not found!" << endl;
}

bool BorrowingService::borrowingExists(int id)
{
    return borrowingRepository.findBorrowing(id) != nullptr;
}
