/*2. Develop a polymorphic subscription system where Basic (B), Premium (P), and Enterprise (E) plans charge 200, 500, and 1000 per user, respectively. Compute the platform’s total monthly revenue.
Input: Number of plans n, followed by n lines containing type and number of users.
Output: Total revenue.*/ 
#include<iostream>
using namespace std;
class Subscription{
    public:
    virtual int total()=0;
};
class Basic{
    public:
    int num1;
    Basic(int a):num1(a){}
    int total()
    {
        return num1*200;
    }
};
class Premium{
    public:
    int num2;
    Premium(int a):num2(a){}
    int total()
    {
        return num2*500;
    }
};class Enterprise{
    public:
    int num3;
    Enterprise(int a):num3(a){}
    int total()
    {
        return num3*1000;
    }
};
int main()
{
    int n,a=0,b=0,c=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int p;
        char ch;
        cin>>ch>>p;
        if(ch=='B')
        a+=p;
        else if(ch=='P')
        b+=p;
        else if(ch=='E')
        c+=p;
    }
    Basic b1(a);
    Premium p1(b);
    Enterprise e1(c);
    cout<<b1.total()+p1.total()+e1.total()<<endl;


}