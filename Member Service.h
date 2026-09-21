#ifndef MEMBERSERVICE_H
#define MEMBERSERVICE_H

#include "Member.h"
#include "MemberRepository.h"

class MemberService
{
private:
    MemberRepository memberRepository;

public:
    void addMember();
    void viewMembers();
    void searchMember();
    void updateMember();
    void deleteMember();

    bool memberExists(int id);
};

#endif // MEMBERSERVICE_H
