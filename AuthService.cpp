#include "AuthService.h"
#include "InputValidator.h"
#include <functional>
#include <sstream>

using namespace std;

string hashPassword(string password)
{
    hash<string> hasher;
    stringstream ss;

    ss << hasher(password);

    return ss.str();
}

void AuthService::registerUser()
{
    string username;
    string password;

    cout << "\n===== Register =====" << endl;

    cout << "Enter username: ";
    cin >> username;

    if (!InputValidator::isNotEmpty(username))
    {
        cout << "Username cannot be empty!" << endl;
        return;
    }

    for (User user : users)
    {
        if (user.username == username)
        {
            cout << "Username already exists!" << endl;
            return;
        }
    }

    cout << "Enter password: ";
    cin >> password;

    if (!InputValidator::isNotEmpty(password))
    {
        cout << "Password cannot be empty!" << endl;
        return;
    }

    users.push_back(
        User(username, hashPassword(password))
    );

    cout << "Users count: " << users.size() << endl;
    cout << "Registration successful!" << endl;
}

bool AuthService::loginUser()
{
    string username;
    string password;

    cout << "\n===== Login =====" << endl;
    cout << "Users count: " << users.size() << endl;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    for (User user : users)
    {
        if (user.username == username &&
            user.password == hashPassword(password))
        {
            cout << "Login successful!" << endl;
            return true;
        }
    }

    cout << "Invalid username or password!" << endl;
    return false;
}
