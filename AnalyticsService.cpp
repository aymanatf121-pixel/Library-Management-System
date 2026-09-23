#include "AnalyticsService.h"
#include <iostream>
#include <map>

using namespace std;

void AnalyticsService::showMostBorrowedBooks(
    BookService &bookService,
    BorrowingService &borrowingService)
{
    cout << "\n===== Most Borrowed Books =====" << endl;

    map<int, int> borrowingCount;

    for (Borrowing borrowing : borrowingService.getAllBorrowings())
    {
        borrowingCount[borrowing.getBookId()]++;
    }

    if (borrowingCount.empty())
    {
        cout << "No borrowing data available." << endl;
        return;
    }

    int mostBorrowedBookId = -1;
    int highestCount = 0;

    for (auto item : borrowingCount)
    {
        if (item.second > highestCount)
        {
            highestCount = item.second;
            mostBorrowedBookId = item.first;
        }
    }

    cout << "Most Borrowed Book ID: "
         << mostBorrowedBookId << endl;

    cout << "Borrowing Count: "
         << highestCount << endl;
}
