#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H
#include "user.h"
#include <vector>
#include <iostream>


class AuthService
{
  private:
      std::vector<User> users;
  public:
void registerUser();
    bool loginUser();
};


#endif // AUTHSERVICE_H
