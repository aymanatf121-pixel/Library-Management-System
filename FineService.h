#ifndef FINESERVICE_H
#define FINESERVICE_H

#include "Fine.h"
#include <vector>

using namespace std;

class FineService
{
private:
    vector<Fine> fines;

public:
    void addFine();
    void viewFines();
    void searchFine();
    void updateFine();
    void deleteFine();
    void payFine();
};

#endif // FINESERVICE_H
