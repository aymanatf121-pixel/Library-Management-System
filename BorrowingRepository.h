#ifndef BORROWINGREPOSITORY_H
#define BORROWINGREPOSITORY_H

#include "Borrowing.h"
#include <vector>

class BorrowingRepository
{
private:
    std::vector<Borrowing> borrowings;

public:
    void addBorrowing(Borrowing borrowing);
    std::vector<Borrowing>& getAllBorrowings();
    Borrowing* findBorrowing(int id);
    bool deleteBorrowing(int id);
};

#endif // BORROWINGREPOSITORY_H
