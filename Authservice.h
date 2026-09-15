#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H
#include "user.h"
#include <vector>
#include <iostream>
using namespace std;


class AuthService
{
  private:
      vector<User> users;
  public:
void registerUser();
    bool loginUser();
};


#endif // AUTHSERVICE_H
