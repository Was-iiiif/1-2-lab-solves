/*Write a program with a base class Shape and a derived class Rectangle. Demonstrate single inheritance by storing dimensions and implement a constructor that allows implicit conversion int(side length) to a Rectangle object*/
#include<iostream>
using namespace std;
class Shape{
protected:
    int length, width;
public:
    Shape(int a,int b):length(a),width(b){}
};

class Rectangle: public Shape{
public:
    Rectangle(int a, int b): Shape(a,b)
    {
        cout<<"Rectangle created"<<endl;
    }
    Rectangle(int length): Shape(length,length)
    {
        cout<<"Implicit type conversion done"<<endl;
    }
    void area(){cout<<"Area is: "<<length*width<<endl;}
    void area2() {cout<<"Area is: "<<length*length<<endl;}

} ;
int main()
{
    int length, width;
    cout<<"Enter length and width:"<<endl;
    cin>>length>>width;
    Rectangle r1(length,width);
    r1.area();
    Rectangle r2(length);
    r2.area2();
}
