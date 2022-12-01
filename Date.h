#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int, int, int);
        Date(const Date &);
        ~Date();
        void setDay(int);
        int getDay();
        void setMonth(int);
        int getMonth();
        void setYear(int);
        int getYear();
        friend istream &operator >>(istream & in, Date &d);
        friend ostream &operator << (ostream &out,const Date &d);
};
#endif