/*Write a program that takes an integer N, then reads N student records, where each record consists of a roll number and a student name.
Store the records in a suitable container so that they can be printed later in the same order as entered.
After displaying the full list of student records, extract all the roll numbers and store them in an appropriate container that automatically keeps them unique and sorted.
Print the distinct roll numbers, and also display how many duplicate roll numbers were entered in the original input.*/

#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int roll;
    string name;
}Student;
int main()
{
    vector<Student>v;
    set<int>uniqueRoll;
    int duplicateRoll;
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        Student s;
        cin>>s.roll>>s.name;
        v.push_back(s);
        if(uniqueRoll.find(s.roll)!=uniqueRoll.end())
            duplicateRoll++;
        uniqueRoll.insert(s.roll);

    }
    for(Student m:v)
    {
        cout<<m.roll<<"=="<<m.name<<endl;
    }
    cout<<"Unique rolls: "<<endl;
    for(auto &x:uniqueRoll)
    {
        cout<<x<<endl;
    }
    cout<<"Num of duplicate rolls: "<<duplicateRoll;



}
