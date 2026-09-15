#include "AuthService.h"
#include "InputValidator.h"
void AuthService::registerUser()
{
    string username;
    string password;

    cout << "\n===== Register =====" << endl;

    cout << "Enter username: ";
    cin >> username;

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

    users.push_back(User(username, password));
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
    cout << "Entered username: " << username << endl;
    cout << "Stored username: " << users[0].username << endl;

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
