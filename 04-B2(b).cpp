/*Implement a multilevel inheritance chain Time-> Time24-> Time12. Demonstrate conversion by implementing a type conversion operator from Time24 to Time12 format, and test it in main.*/
#include<bits/stdc++.h>
using namespace std;

class Time{
protected:
    int hour, minute;
public:
    Time(int a=0,int b=0):hour(a), minute(b){}
};

class Time24:public Time{
public:
    Time24(int a=0, int b=0):Time(a,b){}
    void display()
    {
        cout<<"Time in 24 hr format: "<<setfill('0')<<setw(2)<<hour<<":"<<minute<<endl;
    }
    operator class Time12();
};

class Time12: public Time24{
protected:
    string period;
public:
    Time12(int a=0, int b=0, string p="AM"):Time24(a,b), period(p){}
    void display()
    {
        cout<<"Time in 12 hr format: "<<setfill('0')<<setw(2)<<hour<<":"<<minute<<" "<<period<<endl;
    }
};
Time24::operator Time12()
{
    int h;
    string p="AM";
    if(hour==0)
    {
        h=12;
        p="AM";
    }
    else if(hour>12)
    {
        h=hour%12;
        p="PM";
    }
    else if(h==12)
    {
        h=12;
        p="PM";
    }
    return Time12(h, minute, p);
}
int main()
{
    int a,b;
    cout<<"Enter hour and minute:"<<endl;
    cin>>a>>b;
    Time24 t1(a,b);
    Time12 t2;
    t2=t1;
    t1.display();
    t2.display();
}
