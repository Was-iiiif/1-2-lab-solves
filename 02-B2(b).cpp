/*Design a HotelRoom class in C++:
A parameterized constructor initializes room number, price, and availability.
A static variable tracks total available rooms.
Provide a bookRoom() and freeRoom() method to update room availability.
Use the destructor to print when a room object is removed.*/

#include<bits/stdc++.h>
using namespace std;
class HotelRoom{
    int num, price;
    bool available;
    static int countRoom;
public:
    HotelRoom(int a, int b, bool c=true)
    {
        num=a;
        price=b;
        available=c;
        if(available)
        {
            countRoom++;
        }
        cout<<"Room "<<num<<" is created"<<endl<<"Available: "<<(available?"YES ":"NO ")<<endl;
    }
    void bookRoom()
    {
        if(available)
        {
            available=false;
            countRoom--;
            cout<<"Room "<<num<<" booked successfully"<<endl;
        }
        else
            cout<<"Room already booked"<<endl;
    }
    void freeRoom()
    {
        if(!available)
        {
            available=true;
            countRoom++;
            cout<<"Room "<<num<<" is available now"<<endl;
        }
        else
            cout<<"Room is already available"<<endl;
    }
    ~HotelRoom()
    {
        cout<<"Room "<<num<<" is destroyed"<<endl;
    }
    int get_count()
    {
        return countRoom;
    }
    void display()
    {
        cout<<"Room: "<<num<<" Price: "<<price<<"$ Status: "<<(available?" AVAILABLE ":" BOOKED")<<endl;
    }
};
int HotelRoom::countRoom=0;
int main()
{
    HotelRoom r1(101, 300, true);
    HotelRoom r2(102, 400, true);
    cout<<"Current number of rooms: "<<r1.get_count()<<endl;
    r1.display();
    r2.display();
    r1.bookRoom();
    cout<<"Current number of rooms: "<<r1.get_count()<<endl;
    r1.freeRoom();
    cout<<"Current number of rooms: "<<r1.get_count()<<endl;
}
