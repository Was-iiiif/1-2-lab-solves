#include<bits/stdc++.h>
using namespace std;
class Person{
public:
    string name;
    int age;
    Person(string a, int b):name(a), age(b){}
};
class Employee: public Person{
public:
    int empID;
    double salary;
    Employee(string a, int b, int c, double d):Person(a,b), empID(c), salary(d){}
};
class Department{
public:
    string deptName;
    string location;
    Department(string e, string f):deptName(e), location(f){}
};
class OfficeStaff: public Employee, public Department{
public:
    OfficeStaff(string a, int b, int c, double d,string e, string f):Employee(a,b,c,d), Department(e,f){}
    void write(ofstream&p)
    {
        p<<name<<" "<<age<<" "<<empID<<" "<<salary<<" "<<deptName<<" "<<location<<endl;
    }
};
int main()
{
    int n;
    cout<<"Number of employees:";
    cin>>n;
    ofstream fout("staff.txt");
    for(int i=0; i<n; i++)
    {
        string a;
        int b,c;
        double d;
        string e,f;
        cin>>a>>b>>c>>d>>e>>f;
        OfficeStaff os(a,b,c,d,e,f);
        os.write(fout);
    }
    fout.close();
    ifstream fin("staff.txt");
        string a;
        int b,c;
        double d;
        string e,f;
    while(fin>>a>>b>>c>>d>>e>>f)
    {
        if(e=="CSE" && d>40000)
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
    }
}

