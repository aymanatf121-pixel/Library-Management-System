#include "BorrowingRepository.h"

void BorrowingRepository::addBorrowing(Borrowing borrowing)
{
    borrowings.push_back(borrowing);
}

std::vector<Borrowing>& BorrowingRepository::getAllBorrowings()
{
    return borrowings;
}

Borrowing* BorrowingRepository::findBorrowing(int id)
{
    for (Borrowing &borrowing : borrowings)
    {
        if (borrowing.getId() == id)
        {
            return &borrowing;
        }
    }

    return nullptr;
}

bool BorrowingRepository::deleteBorrowing(int id)
{
    for (auto it = borrowings.begin(); it != borrowings.end(); ++it)
    {
        if (it->getId() == id)
        {
            borrowings.erase(it);
            return true;
        }
    }

    return false;
}
