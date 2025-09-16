/*Create a Result class:
A constructor initializes marks in n subjects. Use dynamic memory allocation wherever necessary.
A static variable tracks the highest average across all students.
Update the highest average whenever a new result is created.
Use the destructor to print when a result object is deleted.*/

#include<bits/stdc++.h>
using namespace std;
class Result{
    double *marks;
    int subjects;
    double avg;
    static double h_avg;
public:
    Result(double m[],int a)
    {
        subjects=a;
        marks=new double[subjects];
        double sum=0.0;
        for(int i=0; i<subjects; i++)
        {
            marks[i]=m[i];
        }
        for(int i=0; i<subjects; i++)
        {
            sum+=m[i];
        }
        if(sum/subjects>h_avg)
            h_avg=sum/subjects;
        cout<<"Student added"<<endl;
    }
    ~Result()
    {
        delete[]marks;
        cout<<"Student deleted"<<endl;
    }
    static double get_h_avg()
    {
        return h_avg;
    }

};

    double Result::h_avg=0.00;

    int main()
    {
        Result::get_h_avg();
        int s1,s2,s3;
        cout<<"Number of subjects for 1st student: "<<endl;
        cin>>s1;
        double m1[s1];
        cout<<"Enter marks: "<<endl;
        for(int i=0; i<s1; i++)
            cin>>m1[i];
        cout<<"Number of subjects for 2nd student: "<<endl;
        cin>>s2;
        double m2[s2];
        cout<<"Enter marks: "<<endl;
        for(int i=0; i<s2; i++)
            cin>>m2[i];
        cout<<"Number of subjects for 1st student: "<<endl;
        cin>>s3;
        double m3[s3];
        cout<<"Enter marks: "<<endl;
        for(int i=0; i<s3; i++)
            cin>>m3[i];
        Result r1(m1,s1);
        cout<<"New Average: "<<r1.get_h_avg()<<endl;
        Result r2(m2,s2);
        cout<<"New Average: "<<r2.get_h_avg()<<endl;
        Result r3(m3,s3);
        cout<<"New Average: "<<r3.get_h_avg()<<endl;
    }


