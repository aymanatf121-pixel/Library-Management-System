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

    if (!InputValidator::isValidEmail(email))
    {
        cout << "Invalid email format!" << endl;
        return;
    }

    cout << "Enter Phone: ";
    cin >> phone;

    if (!InputValidator::isValidPhone(phone))
    {
        cout << "Invalid phone number! Phone must contain 11 digits." << endl;
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
        cout << "ID: " << member.getId() << endl;
        cout << "Name: " << member.getName() << endl;
        cout << "Email: " << member.getEmail() << endl;
        cout << "Phone: " << member.getPhone() << endl;
        cout << "Address: " << member.getAddress() << endl;
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
        cout << "Name: " << member->getName() << endl;
        cout << "Email: " << member->getEmail() << endl;
        cout << "Phone: " << member->getPhone() << endl;
        cout << "Address: " << member->getAddress() << endl;
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

    if (!InputValidator::isValidEmail(newEmail))
    {
        cout << "Invalid email format!" << endl;
        return;
    }

    cout << "Enter new phone: ";
    cin >> newPhone;

    if (!InputValidator::isValidPhone(newPhone))
    {
        cout << "Invalid phone number! Phone must contain 11 digits." << endl;
        return;
    }

    cout << "Enter new address: ";
    cin >> newAddress;

    if (!InputValidator::isNotEmpty(newAddress))
    {
        cout << "Address cannot be empty!" << endl;
        return;
    }

    member->setName(newName);
    member->setEmail(newEmail);
    member->setPhone(newPhone);
    member->setAddress(newAddress);

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
