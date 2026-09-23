#ifndef BORROWINGSERVICE_H
#define BORROWINGSERVICE_H

#include <vector>

#include "Borrowing.h"
#include "BorrowingRepository.h"
#include "BookService.h"
#include "Member Service.h"
class BorrowingService
{
private:
    BorrowingRepository borrowingRepository;

public:
    void borrowBook(BookService &bookService, MemberService &memberService);
    void viewBorrowings();
    void returnBook(BookService &bookService);
    void searchBorrowing();

    bool borrowingExists(int id);
    std::vector<Borrowing> getAllBorrowings();
};

#endif // BORROWINGSERVICE_H
