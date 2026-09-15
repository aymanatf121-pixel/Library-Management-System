#include "Member Service.h"
#include <iostream>
#include <string>

using namespace std;

void MemberService::addMember()
{
    int id;
    string name;
    string email;
    string phone;
    string address;

    cout << "\n===== Add Member =====" << endl;

    cout << "Enter Member ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Email: ";
    cin >> email;

    cout << "Enter Phone: ";
    cin >> phone;

    cout << "Enter Address: ";
    cin >> address;

    members.push_back(Member(id, name, email, phone, address));

    cout << "Member added successfully!" << endl;
}

void MemberService::viewMembers()
{
    cout << "\n===== Members List =====" << endl;

    if (members.empty())
    {
        cout << "No members available." << endl;
        return;
    }

    for (Member member : members)
    {
        cout << "ID: " << member.id << endl;
        cout << "Name: " << member.name << endl;
        cout << "Email: " << member.email << endl;
        cout << "Phone: " << member.phone << endl;
        cout << "Address: " << member.address << endl;
        cout << "------------------------" << endl;
    }
}

void MemberService::searchMember()
{
    int id;

    cout << "\n===== Search Member =====" << endl;
    cout << "Enter Member ID: ";
    cin >> id;

    for (Member member : members)
    {
        if (member.id == id)
        {
            cout << "Member found!" << endl;
            cout << "Name: " << member.name << endl;
            cout << "Email: " << member.email << endl;
            cout << "Phone: " << member.phone << endl;
            cout << "Address: " << member.address << endl;
            return;
        }
    }

    cout << "Member not found!" << endl;
}

void MemberService::updateMember()
{
    int id;

    cout << "\n===== Update Member =====" << endl;
    cout << "Enter Member ID: ";
    cin >> id;

    for (Member &member : members)
    {
        if (member.id == id)
        {
            cout << "Enter new name: ";
            cin >> member.name;

            cout << "Enter new email: ";
            cin >> member.email;

            cout << "Enter new phone: ";
            cin >> member.phone;

            cout << "Enter new address: ";
            cin >> member.address;

            cout << "Member updated successfully!" << endl;
            return;
        }
    }

    cout << "Member not found!" << endl;
}

void MemberService::deleteMember()
{
    int id;

    cout << "\n===== Delete Member =====" << endl;
    cout << "Enter Member ID: ";
    cin >> id;

    for (auto it = members.begin(); it != members.end(); ++it)
    {
        if (it->id == id)
        {
            members.erase(it);
            cout << "Member deleted successfully!" << endl;
            return;
        }
    }

    cout << "Member not found!" << endl;
}

