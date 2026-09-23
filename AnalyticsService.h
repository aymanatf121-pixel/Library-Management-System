#ifndef ANALYTICSSERVICE_H
#define ANALYTICSSERVICE_H

#include "BookService.h"
#include "Member Service.h"
#include "BorrowingService.h"
#include "AccountingService.h"

class AnalyticsService
{
public:
    void showMostBorrowedBooks(
        BookService &bookService,
        BorrowingService &borrowingService
    );

    void showMostActiveMembers(
        MemberService &memberService,
        BorrowingService &borrowingService
    );

    void showMonthlyFineRevenue(
        AccountingService &accountingService
    );
};

#endif // ANALYTICSSERVICE_H
