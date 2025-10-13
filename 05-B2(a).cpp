/*
Employee Salary Calculation:
In a company, salary depends on both work hours and performance. Create a C++ program using hybrid inheritance with classes:
Employee (ID, Name), Work (hours, rate/hour), and Performance (rating).
Derive a final class Salary from both Work and Performance that calculates
total_salary = (hours_worked * rate_per_hour) + (rating * 1000)
Use parameterized constructors in all classes and show the constructor calling order.
*/
#include<iostream>
using namespace std;
class Employee{
protected:
    int id;
    string name;
public:
    Employee(int a, string b):id(a), name(b)
    {
        cout<<"Employee called"<<endl;
    }
};
class Work: virtual public Employee{
protected:
    int hours;
    double rate;
public:
    Work(int a, string b, int c, double d):Employee(a,b), hours(c), rate(d)
    {
        cout<<"Work called"<<endl;
    }
};
class Performance: virtual public Employee{
protected:
    double rating;
public:
    Performance(int a, string b, double e):Employee(a,b), rating(e)
    {
        cout<<"Performance called"<<endl;
    }
};
class Salary: public Work, public Performance{
public:
    Salary(int a, string b, int c, double d, double e):Employee(a,b),Work(a,b,c,d), Performance(a,b,e)
    {
        cout<<"Salary called"<<endl;
    }
    void salary()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Hours worked: "<<hours<<endl;
        cout<<"Rate per hour: "<<rate<<endl;
        cout<<"Rating: "<<rating<<endl;
        cout<<"Salary: "<< (hours * rate) + (rating * 1000)<<endl;
    }

};
int main()
{
    int a;
    string b;
    int c;
    double d,e;
    cout<<"Enter ID, name, hours worked, rate per hour, rating and salary: "<<endl;
    cin>>a>>b>>c>>d>>e;
    Salary m(a,b,c,d,e);
    m.salary();
}
