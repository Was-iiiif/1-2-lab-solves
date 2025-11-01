/*2. Develop a toll booth system that calculates the total toll based on vehicle type using polymorphism. Each vehicle type (C=Car, B=Bus, T=Truck) pays a fixed toll (100, 250, 400, respectively).
Input: Number of vehicles n, followed by n lines of vehicle types.
Output: Total toll collected.*/
#include<bits/stdc++.h>
using namespace std;
class Vehicle{
public:
    int num1;
    Vehicle(int a):num1(a){}
    virtual int toll()=0;
};
class C: public Vehicle{
public:
    int num2;
    C(int a, int b):Vehicle(a), num2(b){}
    int toll()
    {
        return num2*100;
    }
};
class B: public Vehicle{
public:
    int num3;
    B(int a, int c):Vehicle(a), num3(c){}
    int toll()
    {
        return num3*250;
    }
};
class T: public Vehicle{
public:
    int num4;
    T(int a, int d):Vehicle(a), num4(d){}
    int toll()
    {
        return num4*400;
    }
};
int main()
{
    int a,b=0,c=0,d=0;
    cout<<"Enter total vehicles"<<endl;
    cin>>a;
    cout<<"Enter vehicle types: "<<endl;
    for(int i=0; i<a; i++)
    {
        char ch;
        cin>>ch;
        if(ch=='C')
            b++;
        else if(ch=='B')
            c++;
        else if(ch=='T')
            d++;
        else
            exit(0);
    }
    C c1(a,b);
    B b1(a,c);
    T t1(a,d);
    Vehicle *v1=&c1;
    Vehicle *v2=&b1;
    Vehicle *v3=&t1;
    int m=v1->toll();
    int n=v2->toll();
    int o=v3->toll();
    cout<<"Total toll is: "<<m+n+o<<endl;



}
