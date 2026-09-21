#ifndef MEMBERREPOSITORY_H
#define MEMBERREPOSITORY_H

#include "Member.h"
#include <vector>

class MemberRepository
{
private:
    std::vector<Member> members;

public:
    void addMember(Member member);
    std::vector<Member>& getAllMembers();
    Member* findMember(int id);
    bool deleteMember(int id);
};

#endif // MEMBERREPOSITORY_H
