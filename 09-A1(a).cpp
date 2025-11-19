/*1. Write a program that reads an integer N, then takes N employee salary records, where each record contains an employee ID and a salary amount.
Store the data using a suitable container so that the records can be printed in order of input.
Then transfer the data into a suitable container that stores the records sorted by employee ID.
Print the sorted list of employees with their salaries, and then display the lowest and highest salary among them.*/

#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int id;
    double salary;
}Employee;
int main()
{
    vector<Employee>v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        Employee emp;
        cin>>emp.id>>emp.salary;
        v.push_back(emp);
    }
    cout<<"FIFO output"<<endl;
    for(const auto& emp:v)
    {
        cout<<emp.id<<" "<<emp.salary<<endl;
    }
    vector<Employee>v2=v;
    sort(v2.begin(),v2.end(),
         [](const Employee&a, const Employee&b)
         {
             return a.id<b.id;
         });
    cout<<"Sorted list"<<endl;
        for(const auto& emp:v2)
    {
        cout<<emp.id<<" "<<emp.salary<<endl;
    }
    vector<Employee>v3=v;
    sort(v3.begin(),v3.end(),
         [](const Employee&a, const Employee&b)
         {
             return a.salary<b.salary;
         });
    cout<<"Highest Salary: "<<v3[n-1].salary<<endl;
    cout<<"Lowest Salary: "<<v3[0].salary<<endl;

}
