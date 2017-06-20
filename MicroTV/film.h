#ifndef FILM_H
#define FILM_H
#include "Account.h"
#include "DateAndTime.h"

class Film
{
    //出于性能因素考虑设置为友元函数，删除电影（实际并未删除，只是设置其 deleted 数据成员设置为为true）
    //现使用层次中的所有删除都是”形式上“的，为便于恢复
    friend void delete_film(Film&);
    friend void recover_film(Film&);
    friend void setFree(Film&);	//设置为免费电影
    friend void setCharged(Film&);
public:
    Film(Film&);//拷贝构造函数，避免不当操作导致 totalFilm 数值增加
    Film(const std::string& ="default", Account* = nullptr, bool = false);	//构造函数，带默认实参
    ~Film();
    void setUploader(Account*);
    Account* getUploader();
    void setTitle(const std::string&);
    std::string getTitle() const;
    bool is_free() const;
    void set_free(bool);
    bool is_deleted() const;
    void set_deleted(bool);
    void helpIncreaseViewTime();
    Film& operator= (Film&);	//重载赋值运算符
    void setUploaderstr(std::string);
    std::string getUploaderstr();
private:
    char title[101];	//片名
    //上传者
    Account* uploader = nullptr;
    //上传时间
    DateAndTime upload_time;
    bool deleted = false;
    bool free = false;
    std::string uploaders;

    //访问次数
    int view_time = 0;
    //记录总影片
    static int totalFilm;
};

#endif // !FILM_H
