#include "Date.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Date::Date()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;

};
Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;

};
Date::Date (const Date &date)
{
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;

};
Date::~Date()
{

};
bool checkDate (int day, int month, int year)
{
    if (year < 0 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day< 1 || day > 31)
        return false;
    if (month == 2)
    {
        if ( year % 400 == 0 || ((year % 4 == 0) && (year %100 != 0)))
        {
            return (day < 30);
        }
        return (day < 29);

    } 
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return (day < 31);

    }
    return (day < 30);
}

void Date::setDay(int day)
{
    this->day = day;
};
int Date::getDay()
{
    return this->day;
}
void Date::setMonth(int month)
{
    this->month = month;
};
int Date::getMonth()
{
    return this->month;
};
void Date::setYear(int year)
{
    this->year = year;
};
int Date::getYear()
{
    return this->year;

};

istream &operator >>(istream & in, Date &d)
{
    bool check = 0;
    while (check == 0)
    {
        putchar('\n');
        cout << "Nhap ngay: ";
        in >> d.day;
        cout << "Nhap thang: ";
        in >> d.month;
        cout << "Nhap nam: ";
        in >> d.year;
        if (checkDate(d.day, d.month, d.year) == 0)
            {
                cout << "Khong hop le, nhap lai \n";
                check = false;
            }
        else check = 1;
        
    }
    return in;
}

ostream &operator << (ostream &out,const Date &d) 
{
    out << right << setw(2) << setfill('0') << d.day << "/" << setw(2) << setfill('0') <<  d.month <<  "/" << d.year << endl;
    return out;
}