/*Design a Course class that manages university course registrations:
Use a parameterized constructor to initialize a course with a name, course code, and maximum capacity. Use dynamic memory allocation wherever necessary.
Use a static variable to track the total number of students registered across all courses.
Implement registerStudent() and dropStudent() methods to manage enrollments.
Use the destructor to automatically reduce the total registered count when a course object is destroyed*/

#include<bits/stdc++.h>
using namespace std;
class Course{
    string name;
    int code, max_cap, registered;
    static int students;
public:
    Course(string a, int b, int c, int d=0)
    {
        name=a;
        code=b;
        max_cap=c;
        registered=d;
        cout<<"Course created"<<endl;
    }
    void registerStudent()
    {
        if(registered<max_cap)
        {
            registered++;
            students++;
            cout<<"New student enrolled to "<<name<<" "<<code<<endl<<"Total students: "<<students<<endl;
        }
        else
            cout<<"Sorry, no seat available"<<endl;
    }

    void dropStudent()
    {
        if(registered>0)
        {
            registered--;
            students--;
            cout<<"Student dropped from "<<name<<" "<<code<<endl<<"Total students: "<<students<<endl;
        }
        else
            cout<<"So student available"<<endl;
    }
    ~Course()
    {
        cout<<"Course "<<name<<" "<<code<<" destroyed"<<endl;
    }
    void display()
    {
        cout<<"Course details:"<<endl;
        cout<<name<<" "<<code<<" Max Capacity: "<<max_cap<<endl;
        cout<<"Total students: "<<students<<endl;
    }
};

    int Course::students=0;
    int main()
    {
        int t=2;
        string name[t];
        int code[t];
        int cap[t];
        for(int i=0; i<t; i++)
        {
            cout<<"Enter course name, code and maximum capacity of students for the course: "<<endl;
            cin>>name[i]>>code[i]>>cap[i];
        }
        Course c1(name[0], code[0], cap[0]);
        c1.display();
        Course c2(name[1], code[1], cap[1]);
        c2.display();
        c1.registerStudent();
        c2.registerStudent();
        c1.dropStudent();

    }
