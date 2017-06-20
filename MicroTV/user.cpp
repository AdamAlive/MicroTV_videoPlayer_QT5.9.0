#include "User.h"
#include<array>
using namespace std;
//类外初始化为0
int User::totalUser = 0;

const string User::deleteMessage = " has been deleted";

const string User::recoverMessage = " has been recovered";

const string User::VipMessage = " has been made VIP";

const string User::conjU = " by User ";


//构造函数
User::User(const string & name, const string & passport, const long int & id, bool vip)
//调用 基类Account 的构造函数

{
    Account::Account(name, passport, id);
    //设置
    if (vip)
        this->vip = true;
    //用户数增加
    ++totalUser;
}

User::~User()
{
    //扫尾工作
    delete[]downloadHistory;

    delete[]uploadHistory;
}

bool User::is_Vip() const
{
    return vip;
}

void User::helpIncreaseDownloadNumber()
{
    ++downloadNumber;
}

void User::downloadFilm(Film & film)
{
    //如果有权限下载且该电影未被删除
    if ((this->is_Vip() || film.is_free()) && !film.is_deleted() && this->downloadNumber<maximalHistoryNumber)
    {
        //电影被浏览次数+1
        film.helpIncreaseViewTime();
        //增加记录容量
        this->downloadHistory[this->downloadNumber] = film;
        this->helpIncreaseDownloadNumber();
    }
    else
        throw invalid_argument("The film is for VIP users only or it has been deleted or you have downloaded 10 films.");
}

//待完善
void User::delete_Film(Film & film)
{
    //是否有权限删除，是否已被删除
    if (this == film.getUploader() && !film.is_deleted())
        delete_film(film);
    else
        throw invalid_argument("You have no right to delete the film or it has been deleted.");
}

void User::recover_Film(Film & film)
{
    //是否有权限删除，是否已被删除
    if (this == film.getUploader() && film.is_deleted())
        recover_film(film);
    else
        throw invalid_argument("You have no right to recover the film or it hasn't been deleted.");
}

Film * const User::getDownloadHistory() const
{
    return downloadHistory;
}

int User::getDownloadNumber() const
{
    return downloadNumber;
}

bool User::is_deleted() const
{
    return this->deleted;
}

void User::helpIncreaseUploadNumber()
{
    ++uploadNumber;
}

void User::messageReminder(const string & message)
{
    if (messageNumber < maximalMessageNumber && message.length() <= 100)
    {
        for (int i = 0; i < message.length(); ++i)
        {
            this->message[messageNumber][i] = message[i];
        }
        this->message[messageNumber][message.length()] = '\0';
        ++messageNumber;
    }
    else
        throw invalid_argument("User's maximal message number has been reached.");
}

//上传电影（详细注释见声明）
void User::uploadFilm(Film & film)
{
    if (!film.is_deleted() && this == film.getUploader() && this->uploadNumber<maximalHistoryNumber)//
    {
        Film* temp1 = this->uploadHistory;
        this->uploadHistory[uploadNumber] = film;
        this->helpIncreaseUploadNumber();
    }
    else
        throw invalid_argument("The film has been deleted or you have uploaded 10 films.");
}

Film * User::getUploadHistory() const
{
    return uploadHistory;
}

int User::getUploadNumber() const
{
    return uploadNumber;
}

//重载赋值运算符
User & User::operator=(const User & user)
{
    this->ID = user.getID();
    this->deleted = user.is_deleted();
    this->vip = user.is_Vip();
    this->founding_time = user.getFounding_time();
    this->setName( user.getName());
    this->setpassport( user.getpassport());
    this->deleted = user.is_deleted();
    this->downloadHistory = user.getDownloadHistory();
    this->downloadNumber = user.getDownloadNumber();
    this->uploadHistory = user.getUploadHistory();
    this->uploadNumber = user.getUploadNumber();
    return *this;
}

void User::setVip()
{
    this->vip = true;
}

void User::setDeleted()
{
    this->deleted = true;
}
void User::setRecovered()
{
    this->deleted = false;
}
void User::setNotVip()
{
    this->vip = false;
}

bool User::getVip()
{
    return this->vip;
}

void User::setVip(bool a)
{
    this->vip = a;
}

/*User& User::opeator=(User &right)
{
     name = right.name;
}*/
