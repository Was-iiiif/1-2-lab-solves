/*Write a C++ program using the concept of class and object.

Create two classes, Student and Result.

The Student class should have private members: name, roll, and department.

The Result class should have private members: marks1, marks2, marks3, marks4, marks5 (five subject marks).

Use member functions to set and display the values of both classes.

Write a non-member function that takes one Student object and one Result object, then performs the following:

Calculate the total and average marks.

Find the highest and lowest marks among the five subjects.

Find the second highest mark among the five subjects.

Finally, this non-member function displays the student details, marks, total, average, highest, lowest, and second highest mark.

Input:
Enter student name: Bob
Enter roll number: 202
Enter department: CSE
Enter marks in 5 subjects: 78 85 92 70 80

Output:
Student Details:
Name: Bob
Roll: 202
Department: CSE
Marks: 78, 85, 92, 70, 80
Total = 405
Average = 81.00
Highest = 92
Lowest = 70
Second highest = 85*/

#include<bits/stdc++.h>
using namespace std;

class student{
    string name, dept;
    int roll;
public:
    void set_val(string a, int b, string c){
        name=a;
        roll=b;
        dept=c;
    }
    string get_name(){
        return name;
        }
    int get_roll(){
        return roll;
         }
string get_dept(){ return dept; }
};
class result{
    double marks[5];
public:
    void set_marks(double p, double q, double r, double s, double t){
        marks[0]=p;
        marks[1]=q;
        marks[2]=r;
        marks[3]=s;
        marks[4]=t;
    }
    double *get_marks(){return marks;}

};
typedef struct{
    double total, average, highest, second, lowest;
}stats;
void sort(int arr[])
{
    for(int i=0; i<5-1; i++)
    {
        for(int j=0; j<5-i-1; j++)
        {
            if(arr[j]<arr[j+1])
            {
                arr[j]^=arr[j+1];
                arr[j+1]^=arr[j];
                arr[j]^=arr[j+1];
            }
        }
    }
}
stats calc(result&r1){
    double*marks=r1.get_marks();
    int arr[5];
    for(int i=0; i<5; i++)
    {
        arr[i]=marks[i];
    }
    sort(arr);
    stats s;
    s.highest=arr[0];
    s.second=arr[1];
    s.lowest=arr[4];
    s.total=0;
    for(int i=0; i<5; i++)
        s.total+=arr[i];
    s.average=s.total/5.0;
    return s;

}
void display(student &s1, stats &s, result&r1)
{
    cout<<"Student Details:"<<endl;
    cout<<"Name: "<<s1.get_name()<<endl<<"Roll: "<<s1.get_roll()<<endl<<"Department: "<<s1.get_dept()<<endl;
    cout<<"Marks: ";
    double*m=r1.get_marks();
    for(int i=0; i<5; i++)
    {
        cout<<m[i]<<" ";
    }
    cout<<"Total: "<<s.total<<endl;
    cout<<"Average: "<<s.average<<endl;
    cout<<"Highest: "<<s.highest<<endl;
    cout<<"Lowest: "<<s.lowest<<endl;
    cout<<"Second Highest: "<<s.second<<endl;
}

int main()
{
    student s1;
    result r1;
    double t1, t2, t3, t4, t5;
    string a1,a2;
    int i1;
    cout<<"Enter student name:";
    cin>>a1;
    cout<<"Enter Roll Number:";
    cin>>i1;
    cout<<"Enter Department:";
    cin>>a2;
    s1.set_val(a1,i1,a2);
    cout<<"Enter marks:";
    cin>>t1>>t2>>t3>>t4>>t5;
    r1.set_marks(t1,t2,t3,t4,t5);
    stats s = calc(r1);
    display(s1,s,r1);
}