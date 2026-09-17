#ifndef MEMBERSERVICE_H
#define MEMBERSERVICE_H

#include "Member.h"
#include <vector>


class MemberService
{
private:
   std:: vector<Member> members;

public:
    void addMember();
    void viewMembers();
    void searchMember();
    void updateMember();
    void deleteMember();
    bool memberExists(int id);
};

#endif // MEMBERSERVICE_H
