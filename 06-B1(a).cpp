/*1. Construct a hospital billing program using virtual functions where the General (G) and Surgery (S) departments charge $500 and $2000 per patient, respectively. The system must calculate the hospital’s total revenue.
Input: Number of departments n, followed by n lines of type and number of patients.
Output: Total revenue.*/

#include<bits/stdc++.h>
using namespace std;
class Revenue{
public:
    int num1;
    Revenue(int a):num1(a){};
    virtual int total()=0;
};
class General: public Revenue{
public:
    int num2;
    General(int a, int b):Revenue(a), num2(b){}
    int total()
    {
        return num2*500;
    }
};
class Surgery: public Revenue{
public:
    int num3;
    Surgery(int a, int b):Revenue(a), num3(b){}
    int total()
    {
        return 2000*num3;
    }
};
int main()
{
    int n,a=0,b=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        char ch;
        int m;
        cin>>ch>>m;
        if(ch=='G')
            a+=m;
        else if(ch=='S')
            b+=m;
    }
    General g(n,a);
    Surgery s(n,b);
    int sum=0;
    int*ptr;
    ptr=&g;
    sum+=ptr->total();
    ptr=&s;
    sum+=ptr->total();
    cout<<sum<<endl;

}

