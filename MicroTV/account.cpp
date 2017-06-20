#include "Account.h"
using namespace std;
//构造函数定义
//默认构造函数，用于创建临时变量

Account::Account(const string & name, const string & passport, const long int & id)
    : founding_time()
{
    setName(name);
    setpassport(passport);
    setID(id);

    //记录增加账户
    ++totalAccount;
}

Account::~Account()
{
}

void Account::setID(const long int &id)
{
    if (id >= 10000000)
    {
        this->ID = id;
    return;
    }
    else
        throw invalid_argument("The ID number is not valid, please try again.");
}

long int Account::getID() const
{
    return this->ID;
}

void Account::setpassport(const string & Passport)
{
    if (validcode(Passport))
    {
        for (int i = 0; i < Passport.length(); ++i)
        {
            this->passport[i] = Passport[i];
        }
        this->passport[Passport.length()] = '\0';
    }
    else
        throw invalid_argument("The passport is not valid, please try again.\nPassport should consist of 6-16 characters.\nSpace cannot be included. \nCan't be pure numbers under 9.\n");
}

//测试输入密码是否合法
bool Account::validcode(const string & passport) const
{
    //长度限制 6 -- 16
    if (passport.length() > 16 || passport.length() < 6)
        return false;
    int counter = 0;
    //字符不能为空格
    for (size_t i = 0; i < passport.length(); ++i)
    {
        if (passport[i] == ' ')
            return false;
        else if (passport[i] >= '0'&&passport[i] <= '9')
            ++counter;
    }
    //不可为9位以下纯数字
    if (counter == passport.length() && counter < 9)
        return false;
    return true;
}

string Account::getpassport() const
{
    return this->passport;
}

//用户名开头和结尾不可为空字符，长度不可超过24
void Account::setName(const string & Name)
{
    if (Name[0] != ' ' && Name[Name.length() - 1] != ' ' && Name.length() <= 24)
    {
        for (int i = 0; i < Name.length(); ++i)
        {
            this->name[i] = Name[i];
        }
        this->name[Name.length()] = '\0';
    }
    else
        throw invalid_argument("The Account Name is not valid, please try again.");
}

string Account::getName() const
{
    return this->name;
}

DateAndTime Account::getFounding_time() const
{
    return this->founding_time;
}

int Account::getTotalAccount()
{
    return totalAccount;
}

//静态数据成员初始化
int Account::totalAccount = 0;
