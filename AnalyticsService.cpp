#include "AnalyticsService.h"
#include <iostream>
#include <map>
#include <string>

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

void AnalyticsService::showMostActiveMembers(
    MemberService &memberService,
    BorrowingService &borrowingService)
{
    cout << "\n===== Most Active Members =====" << endl;

    map<int, int> memberBorrowingCount;

    for (Borrowing borrowing : borrowingService.getAllBorrowings())
    {
        memberBorrowingCount[borrowing.getMemberId()]++;
    }

    if (memberBorrowingCount.empty())
    {
        cout << "No borrowing data available." << endl;
        return;
    }

    int mostActiveMemberId = -1;
    int highestCount = 0;

    for (auto item : memberBorrowingCount)
    {
        if (item.second > highestCount)
        {
            highestCount = item.second;
            mostActiveMemberId = item.first;
        }
    }

    cout << "Most Active Member ID: "
         << mostActiveMemberId << endl;

    cout << "Borrowing Count: "
         << highestCount << endl;
}

void AnalyticsService::showMonthlyFineRevenue(
    AccountingService &accountingService)
{
    cout << "\n===== Monthly Fine Revenue =====" << endl;

    map<string, double> monthlyRevenue;

    for (Transaction transaction : accountingService.getAllTransactions())
    {
        string date = transaction.getDate();

        if (date.length() >= 7)
        {
            string month = date.substr(0, 7);
            monthlyRevenue[month] += transaction.getAmount();
        }
    }

    if (monthlyRevenue.empty())
    {
        cout << "No transaction data available." << endl;
        return;
    }

    for (auto item : monthlyRevenue)
    {
        cout << "Month: " << item.first << endl;
        cout << "Revenue: " << item.second << endl;
        cout << "------------------------" << endl;
    }
}
