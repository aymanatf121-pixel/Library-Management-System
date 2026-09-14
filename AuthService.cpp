#include "AuthService.h"

void AuthService::registerUser()
{
    string username;
    string password;

    cout << "\n===== Register =====" << endl;

    cout << "Enter username: ";
    cin >> username;

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

    if (password.empty())
    {
        cout << "Password cannot be empty!" << endl;
        return;
    }

    users.push_back(User(username, password));

    cout << "Registration successful!" << endl;
}

bool AuthService::loginUser()
{
    string username;
    string password;

    cout << "\n===== Login =====" << endl;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    for (User user : users)
    {
        if (user.username == username && user.password == password)
        {
            cout << "Login successful!" << endl;
            return true;
        }
    }

    cout << "Invalid username or password!" << endl;
    return false;
}
