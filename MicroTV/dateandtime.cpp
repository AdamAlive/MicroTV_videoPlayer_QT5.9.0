#include "DateAndTime.h"
#include<string>
using namespace std;
DateAndTime::DateAndTime()
{

    struct tm*t;
    time_t tt;
    time(&tt);//接受一个 time_t 类型的地址值，把时间存在指针所指的位置
    t = localtime(&tt);
    year = t->tm_year + 1900;
    month = t->tm_mon + 1;
    day = t->tm_mday;
    hour = t->tm_hour;
    minute = t->tm_min;
    second = t->tm_sec;

}

DateAndTime::DateAndTime(int yr, int mon, int dy, int h, int min, int sec)
{
    setYear(yr);
    setMonth(mon);
    setDay(dy);
    setHour(h);
    setMinute(min);
    setSecond(sec);
    unsigned int DayofMon[monthsPerYear + 1] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


}

DateAndTime::~DateAndTime()
{
}

inline void DateAndTime::setYear(int y)
{
    this->year = y;
}

inline void DateAndTime::setMonth(int m)
{
    if (m >= 1 && m <= 12)
        this->month = m;
    else
        throw invalid_argument("month must be 1-12");
}

inline void DateAndTime::setDay(int dy)
{
    this->day = checkDay(dy); // validate the day
}

inline void DateAndTime::setHour(int h)
{
    if (h >= 0 && h < 24)
        this->hour = h;
    else
        throw invalid_argument("hour must be 0-23");
}

inline void DateAndTime::setMinute(int m)
{
    if (m >= 0 && m < 60)
        this->minute = m;
    else
        throw invalid_argument("minute must be 0-59");
}

inline void DateAndTime::setSecond(int s)
{
    if (s >= 0 && s < 60)
        this->second = ((s >= 0 && s < 60) ? s : 0);
    else
        throw invalid_argument("second must be 0-59");
}
unsigned int DateAndTime::checkDay(int testDay) const
{
    const array< int, monthsPerYear + 1 > daysPerMonth = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    // determine whether testDay is valid for specified month
    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    // February 29 check for leap year
    if (month == 2 && testDay == 29 && (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    throw invalid_argument("Invalid day for current month and year");
}
void DateAndTime::tick()
{
    if (second < 59)
        second++;
    else
    {
        if (minute < 59)
        {
            minute++;
            second = 0;
        }
        else
        {
            if (hour < 23)
            {
                hour++;
                minute = 0;
                second = 0;
            }
            else
            {
                if (day < DayofMon[day])
                {
                    day++;
                    hour = 0;
                    minute = 0;
                    second = 0;
                }
                else if (month == 2 && day == 28 && (year % 400 == 0 ||
                    (year % 4 == 0 && year % 100 != 0)))
                {
                    day++;
                    hour = 0;
                    minute = 0;
                    second = 0;
                }
                else
                {
                    if (month < 12)
                    {
                        month++;
                        day = 1;
                        hour = 0;
                        minute = 0;
                        second = 0;
                    }
                    else
                    {
                        year++;
                        month = 1;
                        day = 1;
                        hour = 0;
                        minute = 0;
                        second = 0;
                    }
                }
            }
        }
    }
}
unsigned int DateAndTime::getYear() const
{
    return year;
}
unsigned int DateAndTime::getMonth() const
{
    return month;
}
unsigned int DateAndTime::getDay() const
{
    return day;
}
unsigned int DateAndTime::getHour() const
{
    return hour;
}
unsigned int DateAndTime::getMinute() const
{
    return minute;
}
unsigned int DateAndTime::getSecond() const
{
    return second;
}
void DateAndTime::printUniversal() const
{
    cout << getYear() << "/" << setfill('0') << setw(2) << getMonth() << "/" << setw(2) << getDay() << "/"
        << setw(2) << getHour() << ":"
        << setw(2) << getMinute() << ":" << setw(2) << getSecond() << endl;
} // end function printUniversal

  // print Time in standard-time format (HH:MM:SS AM or PM)
void DateAndTime::printStandard()
{
    cout << getYear() << "/" << setfill('0') << setw(2) << getMonth() << "/" << setw(2) << getDay() << getDay()
        << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        << ":" << setw(2) << getMinute()
        << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM") << endl;
} // end function printStandard

/*string DateAndTime::returnStandard()
{
    string re = getYear() + "/" + getMonth() + "/" + getDay() + "/" + ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) + ":" + getMinute() + getSecond() + (hour < 12 ? " AM" : " PM");
    return re;
}*/

DateAndTime & DateAndTime::operator=(const DateAndTime & t)
{
    year = t.year;
    month = t.month;
    day = t.day;
    hour = t.hour;
    minute = t.minute;
    second = t.second;
    return *this;
}
