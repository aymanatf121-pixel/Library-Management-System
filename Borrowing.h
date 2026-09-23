#ifndef BORROWING_H
#define BORROWING_H

#include <string>

class Borrowing
{
private:
    int id;
    int memberId;
    int bookId;
    std::string borrowDate;
    std::string returnDate;
    std::string status;

public:
    Borrowing(
        int i,
        int m,
        int b,
        std::string bd,
        std::string rd,
        std::string s
    );

    int getId() const;
    int getMemberId() const;
    int getBookId() const;
    std::string getBorrowDate() const;
    std::string getReturnDate() const;
    std::string getStatus() const;

    void setReturnDate(std::string rd);
    void setStatus(std::string s);
};

#endif // BORROWING_H
