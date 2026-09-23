#include "Borrowing.h"

Borrowing::Borrowing(
    int i,
    int m,
    int b,
    std::string bd,
    std::string rd,
    std::string s)
{
    id = i;
    memberId = m;
    bookId = b;
    borrowDate = bd;
    returnDate = rd;
    status = s;
}

int Borrowing::getId() const
{
    return id;
}

int Borrowing::getMemberId() const
{
    return memberId;
}

int Borrowing::getBookId() const
{
    return bookId;
}

std::string Borrowing::getBorrowDate() const
{
    return borrowDate;
}

std::string Borrowing::getReturnDate() const
{
    return returnDate;
}

std::string Borrowing::getStatus() const
{
    return status;
}

void Borrowing::setReturnDate(std::string rd)
{
    returnDate = rd;
}

void Borrowing::setStatus(std::string s)
{
    status = s;
}
