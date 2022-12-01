#ifndef AC_H
#define AC_H
#include <iostream>
#include "Date.h"

class AC
{
    private:
        // int quantity;
        string ID;
        bool status;
        Date installDay;
        Date uninstallDay;
        Date warrantyDay;
    public: 
        AC();
        AC(string, bool, Date, Date, Date);
        AC(const AC &);
        ~AC();
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
        friend istream &operator >>(istream& in, AC& );
        friend ostream &operator <<(ostream & out, const AC& );



};

#endif