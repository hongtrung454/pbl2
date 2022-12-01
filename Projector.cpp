#include "Projector.h"

#include <iostream>
#include <string>
#include <iomanip>

Projector::Projector()
{
    this->ID = "";
    this->status = 0;
    this->installDay = Date();
    this->uninstallDay = Date();
    this->warrantyDay = Date();

}
Projector::Projector(string id, bool status, Date installDay, Date uninstallDay, Date warrantyDay)
{
    this->ID = id;
    this->status = status;
    this->installDay = installDay;
    this->uninstallDay = uninstallDay;
    this->warrantyDay = warrantyDay;

}
Projector::Projector(const Projector& f)
{
    this->ID = f.ID;
    this->status = f.status;
    this->installDay = f.installDay;
    this->uninstallDay = f.uninstallDay;
    this->warrantyDay = f.warrantyDay;
}
Projector::~Projector()
{

}
void Projector::setID(string id)
{
    this->ID = id;
}
void Projector::setStatus(bool status)
{
    this->status = status;
}
void Projector::setInstallDay(Date installday)
{
    this->installDay = installday;
}
void Projector::setUninstallDay(Date uninsDay)
{
    this->uninstallDay = uninsDay;
}
void Projector::setWarrantyDay(Date warrantyDay)
{
    this->warrantyDay = warrantyDay;
}
string Projector::getID()
{
    return this->ID;
}
bool Projector::getStatus()
{
    return this->status;
}
Date Projector::getInstallDay()
{
    return this->installDay;
}
Date Projector::getUninstallDay()
{
    return this->uninstallDay;
}
Date Projector::getWarrantyDay()
{
    return this->warrantyDay;
}

istream &operator >>(istream& in, Projector& f)
{
    cout << "Nhap ID may: ";
        fflush(stdin);
        getline(in, f.ID);
    cout << "Nhap tinh trang may (0: Hong, 1: Tot): ";
        in >> f.status;
    cout << "Nhap ngay lap: ";
    in >> f.installDay;
    cout << "Thiet bi co ngay thao khong (0: khong, 1: co): ";
    bool checkUnins; 
    cin >> checkUnins;
    if (checkUnins == 1)
    {
        cout << "Nhap ngay thao: ";
        in >> f.uninstallDay;
    }
    else f.uninstallDay = Date();
    // cout << "Nhap ngay thao: ";
    // in >> f.uninstallDay;
    cout << "Nhap han bao hanh: ";
    in >> f.warrantyDay;
    return in;

}
ostream &operator <<(ostream & out, const Projector& f)
{
    string sStatus = (f.status) ? "Tot" : "Hong";
    out << f.ID << "|" << sStatus << endl;
    out << "Ngay lap: " ;
    out << f.installDay;
    out << "Ngay thao: ";
    out << f.uninstallDay;
    out << "Han bao hanh: ";
    out << f.warrantyDay << endl;
    return out;
    

}

