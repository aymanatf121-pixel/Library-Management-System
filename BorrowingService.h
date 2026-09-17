#ifndef BORROWINGSERVICE_H
#define BORROWINGSERVICE_H

#include "Borrowing.h"
#include "BookService.h"
#include "Member Service.h"
#include <vector>

using namespace std;

class BorrowingService
{
private:
    vector<Borrowing> borrowings;

public:
    void borrowBook(BookService &bookService, MemberService &memberService);
    void viewBorrowings();
    void returnBook(BookService &bookService);
    void searchBorrowing();
    bool borrowingExists(int id);
};

#endif // BORROWINGSERVICE_H
