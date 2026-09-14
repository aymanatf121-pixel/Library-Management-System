#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
public:
    string username;
    string password;

    User(string username, string password)
    {
        username = username;
        password = password;
    }
};

#endif// USER_H
