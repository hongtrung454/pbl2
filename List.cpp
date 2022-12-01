#include "List.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "Fan.h"
#include "Light.h"
#include "AC.h"
#include "Projector.h"
using namespace std;
template <class T>
List<T>::List()
{
    this->pointer = NULL;
    this->size = 0;
}
// List::List(List& L)   // lam sau
// {
//     this->sizeOfFan = L.sizeOfFan;
//     this->sizeOfAC = L.sizeOfAC;
//     this->sizeOfLight = L.sizeOfLight;
//     this->sizeOfProjector = L.sizeOfProjector;
//     if (this->FAN != NULL)
//         delete [] FAN;

// }
template <class T>
List<T>::List(int size)
{
    this->size = size;
    if (this->size == 0)
        this->pointer = NULL;
    else 
        this->pointer = new T[this->size];
}
template <class T>
List<T>::~List()
{
    this->size = 0;


    if (this->pointer != NULL)
        delete [] this->pointer;
 
}

template <class T> 
T & List<T>::operator[](const int& index) 
{
    static T notfound;
    if (index >= 0 && index < this->size)
        {
            return *(this->pointer + index);
        }
    else
        return notfound;
};
template <class T>
List<T> & List<T>::operator=( List& L1)
{
    this->size = L1.size;
    if (this->pointer != NULL)
        {
            delete [] pointer;
        }
    this-> pointer = new T[size];
    for (int i =0; i < size; i++)
    {
        (*this)[i] = L1[i];
    }
    return *this;
}
template <class T>
void List<T>::setID()
{
    
}

template <class T>
int List<T>::getSize()
{
    return this->size;
}

template <class T>
void List<T>::setSize(int size)
{
    this->size = size;
}

template <class T>
void List<T>::Show()
{
    for (int i = 0; i < this->size; i++)
    {
        cout << (*this)[i] << "\n";
    }
}

template <class T>
void List<T>::Add(const T& equipment, int index)
{
    if (index > this->size || index < 0)
        {
            cout <<"Vi tri khong hop le";
            return;
        }
    
    T *temp = this->pointer;
    this->size++;
    this->pointer = new T[this->size];
    for(int i = 0; i < index; i++)
    {
        (this->pointer)[i] = *(temp+i);
    }
    (this->pointer)[index] = equipment;
    for (int i = index + 1; i < this->size; i++)
    {
        (this->pointer)[i] = *(temp + i-1);
    }
    delete []temp;
};

template <class T>
void List<T>::AddToTail(const T& e)
{
    this->Add(e, this->size);
}
template <class T>
void List<T>::Update(int index)
{
    if (index >= this->size || index < 0)
    {
        cout << "Vi tri khong hop le\n";
        return;
    }
    cin >> (*this)[index];
}
template <class T>
void List<T>::Delete(int index)
{
    if (index >= this->size || index < 0)
    {
        cout <<"Vi tri khong hop le\n";
        return;
    }
    T* tmp = this->pointer;
    this->pointer = new T[this->size - 1];
    for (int i = 0, j= 0; i< this->size; i++)
    {
        if( i!= index)
        {
            (*this)[j] = *(tmp+i)     ;
            j++;   
        }
    }
    this->size--;
    delete [] tmp;
}
template <class T>
void List<T>::DeleteTail()
{
    Delete(this->size-1);
}


template <class T>
void List<T>::AddList()
{
    if(this->pointer != NULL)
    {
        delete [] this->pointer;
    }
    cout << "Nhap kich thuoc danh sach: ";
    cin >> this->size;
    putchar('\n');
    this->pointer = new T[this->size];

    for (int i = 0; i < this->size; i++)
    {
        cin >>(*this)[i];
        putchar('\n');
    }
}

template class List<Fan>;
template class List<Light>;
template class List<AC>;
template class List<Projector>;
