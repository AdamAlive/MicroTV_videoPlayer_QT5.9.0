#ifndef USER_H
#define USER_H
#include "Account.h"
#include "Film.h"

//虚继承 Account类
class User :public virtual Account
{
public:

    //User operator=(User&);

    //含有默认实参的 User 构造函数
    User(const std::string & = "default", const std::string & = "A11111", const long int & = 10000000 + Account::getTotalAccount(), bool = false);

    //虚析构函数
    virtual~User();

    //重写 account 的纯虚函数 downloadFilm
    //浏览（下载）一部电影
    virtual void downloadFilm(Film &);

    //删除一部电影，仅当该电影是当前用户上传时执行，不然会抛出异常
    //删除操作仅仅设置电影的 deleted 数据成员设置为为true
    virtual void delete_Film(Film &);

    virtual void recover_Film(Film &);

    //判断是否为 VIP用户
    bool is_Vip() const;

    void setVip();

    void setDeleted();

    void setRecovered();

    void setNotVip();

    //返回存放已下载电影的数组首地址
    Film * const getDownloadHistory()const;

    //返回下载电影数
    int getDownloadNumber() const;

    //返回存放已上传电影的数组首地址
    Film * getUploadHistory()const;

    //返回上传电影数
    int getUploadNumber() const;

    //账户是否被删除
    bool is_deleted() const;

    bool getVip();
    void setVip(bool);

    //上传一部电影，该操作将一部电影和其上传者相联系
    //具体使用时，先创建 Film 对象，其中一个参数为当前处于登陆状态的用户
    //然后调用该函数，修改其中的 uploadHistory 数据成员，使其指向一个大小为 （uploadNumber+1）的Film数组
    //复制之前的信息，并在末尾添加新上传的电影对象
    void uploadFilm(Film&);

    User& operator= (const User&);

    static const int maximalMessageNumber = 20;

    static const int maximalHistoryNumber = 10;

    //用于接收各类信息的消息数组，目前计划为在删除用户自己上传的电影，以及被管理员删除电影
    std::array<char[101], maximalMessageNumber> message;

    int messageNumber;

    static const std::string deleteMessage;

    static const std::string recoverMessage;

    static const std::string VipMessage;

    static const std::string conjU;
protected:

    //增加下载数，防止不当操作
    void helpIncreaseDownloadNumber();

    //增加上传数，防止不当操作
    void helpIncreaseUploadNumber();

    //上传历史记录，初始化为可上传10部
    Film* uploadHistory = new Film[maximalHistoryNumber];

    //上传数
    int uploadNumber = 0;

    //下载历史记录，初始化为可下载10部
    Film* downloadHistory = new Film[maximalHistoryNumber];//下载历史记录(初始化时暂时忽略)

                                                           //下载数
    int downloadNumber = 0;
    bool vip = false;
    bool deleted = false;

    void messageReminder(const std::string&);


private:

    //记录总用户账户数
    static int totalUser;
};

#endif // !USER_H



