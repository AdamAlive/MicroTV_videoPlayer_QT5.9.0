#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include "DateAndTime.h"
#include <iostream>

class Account
{
public:
    //Account构造函数
    Account(const std::string & = "default", const std::string & = "dafault", const long int & = 10000000 + Account::getTotalAccount());

    //虚析构函数
    virtual~Account();

    //设置ID
    void setID(const long int&);

    //获取ID
    long int getID() const;

    //设置密码
    void setpassport(const std::string&);

    //获取密码
    std::string getpassport() const;

    //设置用户名
    void setName(const std::string&);

    //获取用户名
    std::string getName() const;

    //获取创建时间
    DateAndTime getFounding_time() const;

    //纯虚函数

                                         //静态成员函数，获取总账户数
    static int getTotalAccount();
protected:
    //用户名
    char name[25];

    //密码
    char passport[17];

    //公有ID从10000000开始，根据创建次序后加
    long int ID = 10000000;

    //创建时间
    DateAndTime founding_time;

private:
    //工具函数
    bool validcode(const std::string & passport) const;

    //记录总账户数
    static int totalAccount;
};


#endif // !ACCOUNT_H
