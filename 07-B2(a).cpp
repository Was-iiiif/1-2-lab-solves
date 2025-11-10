/*1. Create a class Employee with private members:
(int id, string name, and float salary)
Use a parameterized constructor to initialize these attributes. Write a program that:

Takes input for 5 employees.

Stores all details in a text file employee.txt (each record in a new line, formatted as id name salary).

Reopens the file, reads all lines, and displays only those employees whose salary is greater than 40,000.*/

#include<bits/stdc++.h>
using namespace std;
class Employee{
    int id;
    string name;
    float salary;
public:
    Employee(int a, string b, float c):id(a), name(b), salary(c){}
    void write(ofstream &p)
    {
        p<<id<<" "<<name<<" "<<salary<<endl;
    }
};
int main()
{
    ofstream fout("employee.txt");
    cout<<"Enter info of 5 employee"<<endl;
    for(int i=0; i<5; i++)
    {
        int id;
        string name;
        float salary;
        cin>>id>>name>>salary;
        Employee emp(id, name, salary);
        emp.write(fout);
    }
    fout.close();
    ifstream fin("employee.txt");
    int id;
    string name;
    float salary;
    while(fin>>id>>name>>salary)
    {
        if(salary>40000)
            cout<<id<<" "<<name<<" "<<salary<<endl;
    }
}
