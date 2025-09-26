/*Create a base class Person and a derived class Student. Demonstrate single inheritance by storing personal details and student roll number and implement a conversion operator that converts student object to int representing a roll number */

#include<iostream>
using namespace std;
class Person{
protected:
    string name;
    int age;
    double height;
    double weight;
public:
    Person(string a, int b, double c, double d):name(a), age(b), height(c), weight(d){}
};

class Student:public Person{
protected:
    int roll;
public:
    Student(string a, int b, double c, double d, int e):Person(a,b,c,d),roll(e)
    {
        cout<<"Student data stored"<<endl;
    }
    operator int()
    {
        int r;
        r=roll;
    }
};
int main()
{
    string a;
    int b;
    double c;
    double d;
    int e;
    cout<<"Enter student name, age, height in cm, weight in kg and roll: "<<endl;
    cin>>a>>b>>c>>d>>e;
    Student s(a,b,c,d,e);
    int r=s;
    cout<<"Roll is: "<<r<<endl;


}
