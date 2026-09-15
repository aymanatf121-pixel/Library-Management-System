#ifndef MEMBERSERVICE_H
#define MEMBERSERVICE_H

#include "Member.h"
#include <vector>

using namespace std;

class MemberService
{
private:
    vector<Member> members;

public:
    void addMember();
    void viewMembers();
    void searchMember();
    void updateMember();
    void deleteMember();
};

#endif // MEMBERSERVICE_H
