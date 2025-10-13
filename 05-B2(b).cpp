/*Student Record Integration:
A university wants to merge academic and sports data into one student record.
Create a C++ program where Student is the base class, inherited by both Academic and Sports. Derive a final class Result from these two and show the ambiguity problem. Solve it and then display constructor calling order.
*/

#include<bits/stdc++.h>
using namespace std;
class Student{
protected:
    int id;
    string name;
public:
    Student(int a, string b):id(a), name(b)
    {
        cout<<"Student called"<<endl;
    }
};
class Academic: virtual public Student{
protected:
    double cg;
public:
    Academic(int a, string b, double d):Student(a,b), cg(d)
    {
        cout<<"Academic called"<<endl;
    }
};
class Sports: virtual public Student{
protected:
    double rating;
public:
    Sports(int a, string b, double e):Student(a,b), rating(e)
    {
        cout<<"Sports called"<<endl;
    }
};
class Result: public Academic, public Sports{
public:
    Result(int a, string b, double d, double e):Student(a,b),Academic(a,b,d), Sports(a,b,e)
    {
        cout<<"Result called"<<endl;
    }
    void display()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<fixed<<setprecision(2)<<setfill('0');
        cout<<"CG: "<<cg<<endl;
        cout<<"Sports Rating: "<<rating<<endl;
    }

};
int main()
{
    int a;
    string b;
    double d,e;
    cout<<"Enter ID, name, CG, sports rating : "<<endl;
    cin>>a>>b>>d>>e;
    Result m(a,b,d,e);
    m.display();
}
