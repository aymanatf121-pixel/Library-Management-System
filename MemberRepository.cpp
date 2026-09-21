#include "MemberRepository.h"

void MemberRepository::addMember(Member member)
{
    members.push_back(member);
}

std::vector<Member>& MemberRepository::getAllMembers()
{
    return members;
}

Member* MemberRepository::findMember(int id)
{
    for (Member &member : members)
    {
        if (member.id == id)
        {
            return &member;
        }
    }

    return nullptr;
}

bool MemberRepository::deleteMember(int id)
{
    for (auto it = members.begin(); it != members.end(); ++it)
    {
        if (it->id == id)
        {
            members.erase(it);
            return true;
        }
    }

    return false;
}
