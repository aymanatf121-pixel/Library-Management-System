#ifndef FINEREPOSITORY_H
#define FINEREPOSITORY_H

#include "Fine.h"
#include <vector>

class FineRepository
{
private:
    std::vector<Fine> fines;

public:
    void addFine(Fine fine);
    std::vector<Fine>& getAllFines();
    Fine* findFine(int id);
    bool deleteFine(int id);
};

#endif // FINEREPOSITORY_H
