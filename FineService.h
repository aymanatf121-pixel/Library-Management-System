#ifndef FINESERVICE_H
#define FINESERVICE_H
#include "Fine.h"
#include "AccountingService.h"
#include "BorrowingService.h"
#include <vector>

using namespace std;

class FineService
{
private:
    vector<Fine> fines;

public:
    void addFine(BorrowingService &borrowingService);
    void viewFines();
    void searchFine();
    void updateFine();
    void deleteFine();
    void payFine(AccountingService &accountingService);
};

#endif // FINESERVICE_H
