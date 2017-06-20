#include "Film.h"
using namespace std;
//初始化为0
int Film::totalFilm = 0;

//友元函数定义
void delete_film(Film& film)
{
    film.deleted = true;
}

void setFree(Film& film)
{
    film.free = true;
}

void recover_film(Film& film)
{
    film.deleted = false;
}

void setCharged(Film& film)
{
    film.free = false;
}

Film::Film( Film& film)
{
    setTitle(film.getTitle());
    setUploader(film.getUploader());
    if (film.is_free())
        free = true;
}
Film::Film(const std::string & title, Account * user, bool is_free)
{
    setTitle(title);
    setUploader(user);
    if (is_free)
        free = true;

    //总数加一
    ++totalFilm;
}
Film::~Film()
{
}

void Film::setTitle(const std::string & title)
{
    if (title[0] != ' '&&title[title.length() - 1] != ' ' && title.length()<=100)
    {
        for (int i = 0; i < title.length(); ++i)
        {
            this->title[i] = title[i];
        }
        this->title[title.length()] = '\0';
    }
    else
        throw invalid_argument("The Film Title is not valid, please try again.");
}

string Film::getTitle() const
{
    string Title = this->title;
    return Title;
}

bool Film::is_free() const
{
    return this->free;
}

bool Film::is_deleted() const
{
    return this->deleted;
}

void Film::helpIncreaseViewTime()
{
    ++view_time;
}

Film & Film::operator=(Film & film)
{
    setTitle(film.getTitle());
    setUploader(film.getUploader());
    if (film.is_free())
        free = true;
    return *this;
}

void Film::setUploader(Account * user)
{
    uploader = user;
}

Account * Film::getUploader()
{
    return uploader;
}



void Film::set_deleted(bool b)
{
    deleted = b;
}

void Film::set_free(bool b)
{
    free = b;
}

string Film::getUploaderstr()
{
    return uploaders;
}

void Film::setUploaderstr(string a)
{
    uploaders = a;
}
