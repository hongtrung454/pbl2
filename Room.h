#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <iomanip>
#include "Fan.h"
#include "Light.h"
#include "Projector.h"
#include "AC.h"
#include "List.h"
#include "Date.h"
using namespace std;
// template <class T>
class Room
{
    private:
        string roomID;
        
        // List *pointer;
    public:
        List <Fan> FanList;
        List <Light> LightList;
        List <Projector> ProjectorList;
        List <AC> ACList;
        Room();
        Room(string);
        ~Room();
        string getRoomID();
        void setRoomID(string);
        void roomMenu();
        template <class T>
        void Menu(List <T>& );
        template <class T>
        void deleteMenu(List <T> &);
        template <class T>
        void addMenu (List <T> & , T& );

        friend istream &operator >>(istream& in, Room&);


};

#endif