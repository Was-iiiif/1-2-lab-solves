/*Write a C++ program using the concept of class and object.

Create two classes, TimeHM and TimeMS, which represent time values. The TimeHM class stores time in hours and minutes (Private members), while the TimeMS class stores time in minutes and seconds (Private members). Implement a program that reads values for objects of these classes and adds one TimeHM object to another TimeMS object. Use a non-member function to perform the addition operation.

Input:
Enter hours and minutes (TimeHM): 1 40
Enter minutes and seconds (TimeMS): 30 50

Output:
First time: 1 hours 40 minutes
Second time: 30 minutes 50 seconds

Result of addition = 2 hours 10 minutes 50 seconds*/

#include<iostream>
using namespace std;
class TimeHM{
    int h, m1;
public:
    void sethm(int a, int b)
    {
        h=a;
        m1=b;
    }
    int geth()
    {
        return h;
    }
    int getm1()
    {
        return m1;
    }
};
class TimeMS{
    int m2, s;
public:
    void setms(int p, int q)
    {
        m2=p;
        s=q;
    }
    int getm2()
    {
        return m2;
    }
    int getsec()
    {
        return s;
    }
};
typedef struct
{
    int hour, second, minute;
}time;
time calc(time t, TimeHM &t1, TimeMS &t2 )
{
    t.hour=0;
    t.minute=0;
    t.second=0;
    int l,m;
    t.hour=t1.geth();
    m=t2.getsec();
    if(m>=60)
    {
        t.minute+=m/60;
        t.second=m%60;
    }
    else
        t.second=m;
    l+=t1.getm1()+t2.getm2();
    if(l>=60)
    {
        t.hour+=l/60;
        t.minute=l%60;

    }
    else
        t.minute=l;
    return t;


}
int main()
{
    TimeHM t1;
    TimeMS t2;
    time t;
    int a,b,c,d;
    cout<<"Enter hours and minutes(TimeHM): ";
    cin>>a>>b;
    t1.sethm(a,b);
    cout<<"Enter minutes and seconds(TimeMS): ";
    cin>>c>>d;
    t2.setms(c,d);
    t=calc(t, t1, t2);
    cout<<"First time: "<<a<<" hours "<<b<<" minutes "<<endl;
    cout<<"Second time: "<<c<<" minutes "<<d<<" seconds "<<endl;
    cout<<"Result of addition= "<<t.hour<<" hours "<<t.minute<<" minutes "<<t.second<<" seconds";
}
