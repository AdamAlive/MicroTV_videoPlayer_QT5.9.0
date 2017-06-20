#ifndef DATEANFTIME_H
#define DATEANFTIME_H
#include <ctime>
#include <array>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <string>

class DateAndTime
{
public:
    DateAndTime();
    DateAndTime(int, int, int, int, int, int);
    ~DateAndTime();
    static const unsigned int monthsPerYear = 12; // months in a year
    void setYear(int); // set hour (after validation)
    void setMonth(int); // set minute (after validation)
    void setDay(int); // set second (after validation)
    void setHour(int); // set hour (after validation)
    void setMinute(int); // set minute (after validation)
    void setSecond(int); // set second (after validation)
    unsigned int getYear() const; // return hour
    unsigned int getMonth() const; // return minute
    unsigned int getDay() const; // return second
    unsigned int getHour() const; // return hour
    unsigned int getMinute() const; // return minute
    unsigned int getSecond() const; // return second
    void tick();
    void printUniversal() const; // output time in universal-time format
    void printStandard(); // output time in standard-time format
    std::string returnStandard();
    DateAndTime& operator= (const DateAndTime&);
private:
    unsigned int month; // 1-12 (January-December)
    unsigned int day; // 1-31 based on month
    unsigned int year; // any year
    unsigned int hour; // 0 - 23 (24-hour clock format)
    unsigned int minute; // 0 - 59
    unsigned int second; // 0 - 59
    unsigned int checkDay(int) const;
    unsigned int  DayofMon[monthsPerYear + 1]; //= { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
};


#endif // !DATEANFTIME_H

