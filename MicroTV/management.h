#ifndef MANAGRMENT_H
#define MANAGRMENT_H
#include "User.h"
#include "Account.h"

//该类使用几率较小，用于菱形继承
class Management :virtual public Account
{
public:
    Management(const std::string & = "default", const std::string & = "111111", const long int & = 10000000 + Account::getTotalAccount());
    virtual~Management();

    //纯虚函数
    virtual void delete_User(User*) = 0;

    //纯虚函数
    virtual void delete_Film(Film&) = 0;
private:
};


#endif // !MANAGRMENT_H




