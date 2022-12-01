#ifndef LIGHT_H
#define LIGHT_H
#include <iostream>
#include "Date.h"

class Light
{
    private:
        // int quantity;
        string ID;
        bool status;
        Date installDay;
        Date uninstallDay;
        Date warrantyDay;
    public: 
        Light();
        Light(string, bool, Date, Date, Date);
        Light(const Light &);
        ~Light();
        void setID(string);
        void setStatus(bool);
        void setInstallDay(Date);
        void setUninstallDay(Date);
        void setWarrantyDay(Date);
        string getID();
        bool getStatus();
        Date getInstallDay();
        Date getUninstallDay();
        Date getWarrantyDay();
        friend istream &operator >>(istream& in, Light& );
        friend ostream &operator <<(ostream & out, const Light& );



};

#endif