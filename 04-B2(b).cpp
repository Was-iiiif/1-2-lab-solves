/*
Design a multilevel inheritance where Person -> Employee -> Manager.
Store general, job and managerial details,
and implement a conversion operator that converts a Manager object into a double representing the total salary.
*/

#include <bits/stdc++.h>
using namespace std;

class Person {
protected :
    string name;
public :
    Person (string name) : name(name) {}
};

class Employee : public Person{
protected :
    int working_hours;
public :
    Employee (string name, int working_hours) : Person(name), working_hours(working_hours) {}
};

class Manager : public Employee{
protected :
    double salary;
public :
    Manager (string name, int working_hours, double salary) : Employee (name, working_hours), salary(salary) {}

    void display() {
        cout << name << " is a Manager, who works for " << working_hours << " hours everyday and earns " << salary << " tk per month.\n";
    }
    operator double() const {
        return salary;
    }
};

int main() {
    Manager m("Addib", 8, 40000.50);

    m.display();
    cout << "Salary output using type conversion : " << (double)m << endl;
    return 0;
}

