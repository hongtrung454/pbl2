#ifndef ROOMLIST_H
#define ROOMLIST_H
#include <iostream>
#include "Room.h"
using namespace std;

class roomList
{
    private:
        Room* pointer;
        int size;
    public:
        roomList();
        roomList(roomList &);
        roomList(int);
        ~roomList();
        int getRoomSize();
        void setRoomSize(int);
        void Show();
        void Add(const Room&, int);
        void AddToTail( Room&);
        void Delete(int);
        void DeleteTail();
        void Update(int);
        Room &operator [](const int &);
        roomList & operator = (roomList&);
        void addRoomList(Room& , int );
        

};
#endif