/*A space mission data processing system integrates telemetry from multiple onboard instruments into a unified spacecraft report.
Write a C++ program where the base class Telemetry stores a packet ID and timestamp. Two classes, Navigation_Module and Power_Module, derive from Telemetry to handle position data (latitude, longitude, altitude) and power metrics (voltage, current) respectively.
Further, two specialized classes, Nav_Processor (from Navigation_Module) and Power_Processor (from Power_Module), analyze the data to calculate derived metrics such as velocity and power efficiency. Finally, a class Mission_Report inherits from both Nav_Processor and Power_Processor.
Use parameterized constructors in all classes to initialize data, print messages to show the constructor calling order.*/
#include<bits/stdc++.h>
using namespace std;
class Telemetry{
protected:
    int id;
    string timestamp;
public:
    Telemetry(int a, string b):id(a), timestamp(b)
    {
        cout<<"Telemetry called"<<endl;
    }
};
class Navigation_Module: virtual public Telemetry{
protected:
    double latitude, longitude, altitude;
public:
    Navigation_Module(int a, string b, double c, double d, double e):Telemetry(a,b), latitude(c), longitude(d), altitude(e)
    {
        cout<<"Navigation_Module called"<<endl;
    }
};
class Power_Module: virtual public Telemetry{
protected:
    double voltage, current;
public:
    Power_Module(int a, string b, double f, double g):Telemetry(a,b), voltage(f), current(g)
    {
        cout<<"Power_Module called"<<endl;
    }
};
class Nav_Processor: public Navigation_Module{
protected:
    double velocity;
public:
    Nav_Processor(int a, string b, double c, double d, double e, double h):Telemetry(a,b), Navigation_Module(a,b,c,d,e), velocity(h)
    {
        cout<<"Velocity called"<<endl;
    }
};
class Power_Processor: public Power_Module{
protected:
    double efficiency;
public:
    Power_Processor(int a, string b, double f, double g, double i):Telemetry(a,b), Power_Module(a,b,f,g), efficiency(i)
    {
        cout<<"Power_Processor called"<<endl;
    }
};
class Mission_Report: public Nav_Processor, public Power_Processor{
public:
    Mission_Report(int a, string b, double c, double d, double e, double f, double g, double h, double i):Telemetry(a,b), Nav_Processor(a,b,c,d,e,h), Power_Processor(a,b,f,g,i)
    {
        cout<<"Mission Report called"<<endl;
    }
    void display()
    {
        cout<<"Mission Report: "<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"timestamp: "<<timestamp<<endl;
        cout<<"latitude: "<<latitude<<"degrees"<<endl;
        cout<<"longitude: "<<longitude<<"degrees"<<endl;
        cout<<"altitude: "<<altitude<<"km"<<endl;
        cout<<"Voltage: "<<voltage<<"V"<<endl;
        cout<<"Current: "<<current<<"A"<<endl;
        cout<<"Velocity: "<<velocity<<"kmph"<<endl;
        cout<<"efficiency"<<efficiency<<"%"<<endl;
    }
};
int main()
{
    int a;
    string b;
    double c,d,e,f,g,h,i;
    cout<<"Enter info: "<<endl;
    cin>>a>>b>>c>>d>>e>>f>>g;
    h=c*d*e*100;
    i=f*g/100;
    Mission_Report m(a,b,c,d,e,f,g,h,i);
    m.display();
    return 0;
}
