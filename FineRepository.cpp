#include "FineRepository.h"

void FineRepository::addFine(Fine fine)
{
    fines.push_back(fine);
}

std::vector<Fine>& FineRepository::getAllFines()
{
    return fines;
}

Fine* FineRepository::findFine(int id)
{
    for (Fine &fine : fines)
    {
        if (fine.id == id)
        {
            return &fine;
        }
    }

    return nullptr;
}

bool FineRepository::deleteFine(int id)
{
    for (auto it = fines.begin(); it != fines.end(); ++it)
    {
        if (it->id == id)
        {
            fines.erase(it);
            return true;
        }
    }

    return false;
}
