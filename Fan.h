#ifndef FAN_H
#define FAN_H
#include <iostream>
#include "Date.h"

class Fan
{
    private:
        // int quantity;
        string ID;
        bool status;
        Date installDay;
        Date uninstallDay;
        Date warrantyDay;
    public: 
        Fan();
        Fan(string, bool, Date, Date, Date);
        Fan(const Fan &);
        ~Fan();
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
        friend istream &operator >>(istream& in, Fan& );
        friend ostream &operator <<(ostream & out, const Fan& );



};

#endif