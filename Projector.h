#ifndef PROJECTOR_H
#define PROJECTOR_H
#include <iostream>
#include "Date.h"

class Projector
{
    private:
        // int quantity;
        string ID;
        bool status;
        Date installDay;
        Date uninstallDay;
        Date warrantyDay;
    public: 
        Projector();
        Projector(string, bool, Date, Date, Date);
        Projector(const Projector &);
        ~Projector();
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
        friend istream &operator >>(istream& in, Projector& );
        friend ostream &operator <<(ostream & out, const Projector& );



};

#endif