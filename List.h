#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
template <class T>
class List
{
    private:
        T *pointer;
        int size;
        string roomID;
    public:
        List ();
        List (List &);
        List(int);
        ~List();
        void setID();
        string getID();
        int getSize();
        void setSize(int);
        void Show();
        void Add(const T&, int);
        void AddToTail(const T&);
        void Delete(int);
        void DeleteTail();
        void Update(int);
        T & operator [](const int&) ;
        List<T> & operator =( List&);
        void AddList();
        // friend std::istream & operator>> (std::istream&, List<T> &) ;
};


#endif