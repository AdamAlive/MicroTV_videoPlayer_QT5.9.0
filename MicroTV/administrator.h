#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "Management.h"
#include "User.h"
#include <string>

//菱形继承，拥有最高权限
class Administrator :virtual public Management, virtual public User
{
public:

    Administrator(const std::string & = "default", const std::string & = "111111", const long int & = 10000000 + Account::getTotalAccount(), bool = false);

    ~Administrator();

    //用于删除普通用户（参数若为管理员则会抛出异常）
    //同时将其中的 uploadHistory 存储的 Film 成员的 deleted 设置为 true
    //还需添加传递message的功能

    //删除电影
    virtual void delete_Film(Film&) final;

    virtual void recover_Film(Film&) final;

    //浏览电影
    virtual void downloadFilm(Film&) final;//浏览（下载）一部电影。
    virtual void setVip(User&) final;

    virtual void delete_User(User*) final;
    virtual void recover_user(User*) final;

    static const std::string conjA;
private:

    //记录总管理账户数
    static int totalAdministrator;

    virtual void sendMessage(const std::string&, User&) final;
};

#endif // !ADMINISTRATOR_H


