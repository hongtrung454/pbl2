#include "Light.h"

#include <iostream>
#include <string>
#include <iomanip>

Light::Light()
{
    this->ID = "";
    this->status = 0;
    this->installDay = Date();
    this->uninstallDay = Date();
    this->warrantyDay = Date();

}
Light::Light(string id, bool status, Date installDay, Date uninstallDay, Date warrantyDay)
{
    this->ID = id;
    this->status = status;
    this->installDay = installDay;
    this->uninstallDay = uninstallDay;
    this->warrantyDay = warrantyDay;

}
Light::Light(const Light& f)
{
    this->ID = f.ID;
    this->status = f.status;
    this->installDay = f.installDay;
    this->uninstallDay = f.uninstallDay;
    this->warrantyDay = f.warrantyDay;
}
Light::~Light()
{

}
void Light::setID(string id)
{
    this->ID = id;
}
void Light::setStatus(bool status)
{
    this->status = status;
}
void Light::setInstallDay(Date installday)
{
    this->installDay = installday;
}
void Light::setUninstallDay(Date uninsDay)
{
    this->uninstallDay = uninsDay;
}
void Light::setWarrantyDay(Date warrantyDay)
{
    this->warrantyDay = warrantyDay;
}
string Light::getID()
{
    return this->ID;
}
bool Light::getStatus()
{
    return this->status;
}
Date Light::getInstallDay()
{
    return this->installDay;
}
Date Light::getUninstallDay()
{
    return this->uninstallDay;
}
Date Light::getWarrantyDay()
{
    return this->warrantyDay;
}

istream &operator >>(istream& in, Light& f)
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
ostream &operator <<(ostream & out, const Light& f)
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

