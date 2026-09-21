#ifndef FINESERVICE_H
#define FINESERVICE_H

#include "Fine.h"
#include "FineRepository.h"
#include "AccountingService.h"
#include "BorrowingService.h"

class FineService
{
private:
    FineRepository fineRepository;

public:
    void addFine(BorrowingService &borrowingService);
    void viewFines();
    void searchFine();
    void updateFine();
    void deleteFine();
    void payFine(AccountingService &accountingService);
};

#endif // FINESERVICE_H
