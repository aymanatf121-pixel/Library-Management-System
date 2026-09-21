#include "Member Service.h"
#include "InputValidator.h"
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

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Member ID!" << endl;
        return;
    }

    if (memberExists(id))
    {
        cout << "Member ID already exists!" << endl;
        return;
    }

    cout << "Enter Name: ";
    cin >> name;

    if (!InputValidator::isNotEmpty(name))
    {
        cout << "Name cannot be empty!" << endl;
        return;
    }

    cout << "Enter Email: ";
    cin >> email;

    if (!InputValidator::isNotEmpty(email))
    {
        cout << "Email cannot be empty!" << endl;
        return;
    }

    cout << "Enter Phone: ";
    cin >> phone;

    if (!InputValidator::isNotEmpty(phone))
    {
        cout << "Phone cannot be empty!" << endl;
        return;
    }

    cout << "Enter Address: ";
    cin >> address;

    if (!InputValidator::isNotEmpty(address))
    {
        cout << "Address cannot be empty!" << endl;
        return;
    }

    memberRepository.addMember(
        Member(id, name, email, phone, address)
    );

    cout << "Member added successfully!" << endl;
}

void MemberService::viewMembers()
{
    cout << "\n===== Members List =====" << endl;

    if (memberRepository.getAllMembers().empty())
    {
        cout << "No members available." << endl;
        return;
    }

    for (Member member : memberRepository.getAllMembers())
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

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Member ID!" << endl;
        return;
    }

    Member* member = memberRepository.findMember(id);

    if (member != nullptr)
    {
        cout << "Member found!" << endl;
        cout << "Name: " << member->name << endl;
        cout << "Email: " << member->email << endl;
        cout << "Phone: " << member->phone << endl;
        cout << "Address: " << member->address << endl;
        return;
    }

    cout << "Member not found!" << endl;
}

void MemberService::updateMember()
{
    int id;

    cout << "\n===== Update Member =====" << endl;

    cout << "Enter Member ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Member ID!" << endl;
        return;
    }

    Member* member = memberRepository.findMember(id);

    if (member == nullptr)
    {
        cout << "Member not found!" << endl;
        return;
    }

    string newName;
    string newEmail;
    string newPhone;
    string newAddress;

    cout << "Enter new name: ";
    cin >> newName;

    if (!InputValidator::isNotEmpty(newName))
    {
        cout << "Name cannot be empty!" << endl;
        return;
    }

    cout << "Enter new email: ";
    cin >> newEmail;

    if (!InputValidator::isNotEmpty(newEmail))
    {
        cout << "Email cannot be empty!" << endl;
        return;
    }

    cout << "Enter new phone: ";
    cin >> newPhone;

    if (!InputValidator::isNotEmpty(newPhone))
    {
        cout << "Phone cannot be empty!" << endl;
        return;
    }

    cout << "Enter new address: ";
    cin >> newAddress;

    if (!InputValidator::isNotEmpty(newAddress))
    {
        cout << "Address cannot be empty!" << endl;
        return;
    }

    member->name = newName;
    member->email = newEmail;
    member->phone = newPhone;
    member->address = newAddress;

    cout << "Member updated successfully!" << endl;
}

void MemberService::deleteMember()
{
    int id;

    cout << "\n===== Delete Member =====" << endl;

    cout << "Enter Member ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Member ID!" << endl;
        return;
    }

    if (memberRepository.deleteMember(id))
    {
        cout << "Member deleted successfully!" << endl;
        return;
    }

    cout << "Member not found!" << endl;
}

bool MemberService::memberExists(int id)
{
    return memberRepository.findMember(id) != nullptr;
}
