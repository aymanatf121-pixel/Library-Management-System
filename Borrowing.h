#ifndef BORROWING_H
#define BORROWING_H

#include <string>


class Borrowing
{
public:
    int id;
    int memberId;
    int bookId;
    std::string borrowDate;
    std::string returnDate;
    std::string status;

    Borrowing(int i, int m, int b, std::string bd, std::string rd, std::string s)
    {
        id = i;
        memberId = m;
        bookId = b;
        borrowDate = bd;
        returnDate = rd;
        status = s;
    }
};

#endif // BORROWING_H
