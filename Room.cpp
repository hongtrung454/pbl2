#include "Room.h"
#include "List.h"
#include <iostream>

using namespace std;


// template <class T>
// void Menu(List <T>& list);
template <class T>
void Room::addMenu (List <T> & list, T& f)
{
    cout << "1. Them vao vi tri chi dinh trong danh sach\n";
    cout << "2. Them vao dau danh sach\n";
    cout << "3. Them vao cuoi danh sach\n";
    cout << "0. Quay lai Menu thiet bi\n";


    cout <<"Nhap lua chon: ";
    int option; cin >> option;
    switch (option)
    {
        case 0:
        {
            Menu(list);
            break;
        }
        case 1:
        {
            cout << "Nhap vi tri can them vao: ";
            int index; cin >> index;
            list.Add(f, index-1);
            break;
        }
        case 2:
        {
            list.Add(f, 0);
            break;
        }
        case 3:
        {
            list.AddToTail(f);
            break;
        }
        default :
        {
            cout <<"Lua chon loi, nhap lai\n";
            addMenu(list, f);
        }
    }

};
template <class T>
void Room::deleteMenu(List <T> &list)
{
    cout <<"1. Xoa phan tu dau danh sach\n"
         <<"2. Xoa phan tu cuoi danh sach\n"
         <<"3. Xoa phan tu tai vi tri chi dinh\n"
         <<"0. Quay lai MENU thiet bi";
    cout <<"Nhap lua chon: ";
    int opt; cin >> opt;
    switch (opt)
    {
        case 0:
        {
            Menu(list);
            break;
        }
        case 1:
        {
            list.Delete(0);
            break;
        }
        case 2:
        {
            list.DeleteTail();
            break;
        }
        case 3:
        {
            cout << "Nhap vi tri can xoa: ";
            int index; cin >> index;
            list.Delete(index-1);
            break;

        }
        default:
        {
            cout << "Lua chon khong hop le, nhap lai\n";
            deleteMenu(list);
        }
    }
};
template <class T>
void Room::Menu(List <T>& list)
{
    cout <<"\n\n\t-------MENU-------\n\n";

    cout << "\t1. Nhap danh sach thiet bi moi\n"
         << "\t2. Hien thi danh sach thiet bi\n"
         << "\t3. Them vao danh sach thiet bi\n"
         << "\t4. Xoa khoi danh sach\n"
         << "\t5. Cap nhat danh sach\n"
         << "\t0. Ket thuc \n";
    cout << "\n Nhap lua chon:";
    int option; cin >> option;

    switch(option)
    {
        case 0:
        {
            break;
        }

        case 1:
        {
            list.AddList();
            cout <<"Hoan tat \n";
            Menu(list);
            break;

        }
        case 2:
        {
            list.Show();
            cout <<"\n Hoan tat\n";
            Menu(list);
            break;
        }
        case 3:
        {
            cout << "Nhap thong tin thiet bi can them \n";
            T f;
            cin >> f;
            addMenu(list, f);
            cout << "Hoan tat\n";
            Menu(list);
            break;
        }
        case 4:
        {
            deleteMenu(list);
            cout <<" Hoan tat.\n";
            Menu(list);
            break;
        }
        case 5:
        {
            cout <<"Nhap vi tri can cap nhat: ";
            int index; cin >> index;
            list.Update(index-1);
            cout << "\nHoan tat\n";
            Menu(list);
            break;
        }
        default:
        {
            cout << "Lua chon khong hop le, nhap lai\n";
            Menu(list);
        }
        

    }
};

void Room::roomMenu () // int roomMenu();
{

    // List <Fan> FanList;
    // List <Light> LightList;
    // List <Projector> ProjectorList;
    // List <AC> ACList;
    bool run = 1;
    do 
    {
        cout << '\n' <<"-------Menu--------" << '\n'
         << "1. Fan\n"
         << "2. Light\n"
         << "3. Projector\n"
         << "4. AC\n"
         << "0. Thoat\n";
        int opt;
        cin >> opt;
        switch(opt)
        {
            case 1:
            {
                Menu(FanList);
                break;
            }
            case 2:
            {
                Menu(LightList);
                break;
            }
            case 3:
            {
                Menu(ProjectorList);
                break;
            }
            case 4:
            {
                Menu(ACList);
                break;
            }
            case 0:
            {
                run = 0;
                break;
            }
        }
    }
    while (run);

}
Room::Room()
{
    // cout << "\n Nhap ma phong: " ;
    // string ID;  fflush(stdin);
    // getline(cin, ID);
    // setRoomID(ID);
    // roomMenu();
    
    this->roomID = "";
    

}
void Room::setRoomID(string roomID)
{
    this-> roomID = roomID;
};
string Room::getRoomID()
{
    return this->roomID;
}
Room::Room(string ID)
{
    setRoomID(ID);
    roomMenu();
}
// Room::~Room()
// {
//     if (roomID != NULL)
//     {
//         FanList.~List();
//         LightList.~list();
//         ACList.~list();
//         ProjectorList.~list();
//     };
// }

// istream &operator >>(istream & in, Room& r)
// {
//     cout << "Nhap ID phong hoc: ";
//     fflush(stdin);
//     getline(in, r.roomID);
//     r.roomMenu();
//     return in;

// }

template class List<Fan>;
template class List<Light>;
template class List<AC>;
template class List<Projector>;