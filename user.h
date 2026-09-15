#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
public:
    string username;
    string password;
     User(string u, string p) : username(u), password(p)
     {

     }


};

#endif// USER_H
