#include "Administrator.h"
using namespace std;
int Administrator::totalAdministrator = 0;//类外初始化为0

const string Administrator::conjA = " by Administrator ";

Administrator::Administrator(const string & name, const string & passport, const long int & id, bool vip)

{
    User::User(name, passport, id, vip);
    ++totalAdministrator;
}

Administrator::~Administrator()
{
}

void Administrator::delete_Film(Film & film)
{
    //是否已被删除
    User* tempU = dynamic_cast<User*>(film.getUploader());
    if (!film.is_deleted()&& tempU)
    {
        delete_film(film);
        string temp = film.getTitle() + deleteMessage + conjA + this->getName();
        this->sendMessage(temp, *tempU);
    }
    else
        throw invalid_argument("The film has been deleted.");
}

void Administrator::recover_Film(Film & film)
{
    User* tempU = dynamic_cast<User*>(film.getUploader());
    //是否已被删除
    if (film.is_deleted()&& tempU)
    {
        recover_film(film);
        string temp = film.getTitle() + recoverMessage + conjA + this->getName();
        this->sendMessage(temp, *tempU);
    }
    else
        throw invalid_argument("The film hasn't been deleted.");
}

void Administrator::downloadFilm(Film & film)
{
    //如果未被删除且仍然有下载额度
    if (!film.is_deleted() && this->downloadNumber < maximalHistoryNumber)
    {
        //电影被浏览次数+1
        film.helpIncreaseViewTime();
        //增加记录容量
        this->downloadHistory[downloadNumber] = film;
        this->helpIncreaseDownloadNumber();
    }
    else
        throw invalid_argument("The film has been deleted or you have downloaded 10 films.");
}

void Administrator::setVip(User & user)
{
    user.setVip();
    string temp = user.getName() + VipMessage + conjA + this->getName();
    this->sendMessage(temp, user);
}

//删除用户
void Administrator::delete_User(User * user)
{
    User* temp1;
    if ((temp1 = dynamic_cast<User*>(user)) && !user->is_deleted())
    {
        Film* del = temp1->getUploadHistory();
        int number = temp1->getUploadNumber();
        for (int i = 0; i < number; ++i)
        {
            //将账户上传的电影删除
            delete_film(del[i]);
            Film film = del[i];
            User* tempU = dynamic_cast<User*>(film.getUploader());
            string temp2 = film.getTitle() + deleteMessage + conjA + this->getName();
            this->sendMessage(temp2, *tempU);
        }
        string temp3 = user->getName() + deleteMessage + conjA + this->getName();
        this->sendMessage(temp3, *user);
        temp1->setDeleted();
    }
    else
        throw invalid_argument("You can't delete an Administrator!");
}

void Administrator::recover_user(User * user)
{
    User* temp1;
    if ((temp1 = dynamic_cast<User*>(user)) && user->is_deleted())
    {
        temp1->setRecovered();
        string temp2 = user->getName() + recoverMessage + conjA + this->getName();
        this->sendMessage(temp2, *user);
        this->sendMessage(temp2, *this);
        Film* del = temp1->getUploadHistory();
        int number = temp1->getUploadNumber();
        for (int i = 0; i < number; ++i)
        {
            //将账户上传的电影删除
            recover_film(del[i]);
            Film film = del[i];
            User* tempU = dynamic_cast<User*>(film.getUploader());
            string temp = film.getTitle() + recoverMessage + conjA + this->getName();
            this->sendMessage(temp, *tempU);
        }
    }
    else
        throw invalid_argument("You can't recover an Administrator!");
}

void Administrator::sendMessage(const string & message, User & user)
{
    if (user.messageNumber < maximalMessageNumber && this->messageNumber < maximalMessageNumber && !user.is_deleted() && message.length() <= 100)
    {

        for (int i = 0; i < message.length(); ++i)
        {
            user.message[messageNumber][i] = message[i];
            this->message[messageNumber][i] = message[i];
        }
        this->message[messageNumber][message.length()] = '\0';
        user.message[messageNumber][message.length()] = '\0';
        ++(this->messageNumber);
        ++user.messageNumber;
    }
    else
        throw invalid_argument("The User's maximal message number has been reached, or the Account has been deleted.");
}
