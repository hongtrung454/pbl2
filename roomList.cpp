#include "roomList.h"

using namespace std;

roomList::roomList()
{
    this->pointer = NULL;
    this->size = 0;
}
roomList::roomList(int size)
{
    this->size = size;
    if(this->size == 0)
        this->pointer = NULL;
    else 
        this->pointer = new Room[this->size];
}

roomList::~roomList()
{
    this->size = 0;
    
    if(this->pointer != NULL)
        delete [] this->pointer;

}
Room &roomList::operator[](const int &index)
{
    static Room notfound;
    if(index >= 0 && index < this->size)
    {
        return *(this->pointer + index);

    }
    else 
        return notfound;

}

roomList & roomList::operator = (roomList& RL1)
{
    this->size = RL1.size;
    if (this->pointer != NULL)
    {
        delete [] pointer;

    }
    this->pointer = new Room[size];
    for (int i = 0; i< size; i++)
    {
        (*this)[i] = RL1[i];

    }
    return *this;
}
int roomList::getRoomSize()
{
    return this->size;

}
void roomList::setRoomSize(int size)
{
    this->size = size;
}
// void roomList::Show()
// {
//     for (int i = 0 ; i< this->size; i++)
//     {

//     }
// }

void roomList::addRoomList( Room& newroom, int index)
{
    if (index > this->size || index < 0)
        {
            cout <<"Vi tri khong hop le";
            return;
        }
    Room *temp = this->pointer;
    this->size++;
    this->pointer = new Room[this->size];
    for (int i = 0; i< index; i++)
    {
        (this->pointer)[i] = *(temp+i);

    }
    (this->pointer)[index] = newroom;
    for (int i = index + 1; i < this->size; i++)
    {
        (this->pointer)[i] = *(temp + i-1);
    }
    delete [] temp;
};

void roomList::AddToTail( Room& r)
{
    this->addRoomList(r, this->size);
}
void roomList::Update(int index)
{
    if (index >= this->size || index < 0)
    {
        cout <<"Vi tri khong hop le\n";
        return;
    }
    cin >> (*this) [index];
}
