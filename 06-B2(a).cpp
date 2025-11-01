/*1. Design a polymorphic tax system where different taxpayer categories compute taxes differently. Each taxpayer is either Salaried (S) or Business (B), with Salaried paying 10% tax if income > 300,000 else 0, and Business always paying 15%. Input: Number of taxpayers n, followed by n lines containing type and income. Output: Payable tax for each taxpayer (2 decimal places).*/
#include<bits/stdc++.h>
using namespace std;
class Tax{
    protected:
    double income;
    public:
    Tax(double a):income(a){}
    virtual double compute()=0;
};
class Salaried:public Tax{
    public:
    Salaried(double a):Tax(a){}
    double compute()
    {
        if(income>300000)
        return (income*0.1);
        else
        return 0.00;
    }
};
class Business:public Tax{
    public:
    Business(double a):Tax(a){}
    double compute()
    {
        return (income*0.15);
    }
};
int main()
{
    int t;
    cin>>t;
    Tax *tx[t];
    for(int i=0; i<t;i++)
    {
        char ch;
        double a;
        cin>>ch>>a;
        if(ch=='S')
        tx[i]= new Salaried(a);
        else if(ch=='B')
        tx[i]=new Business(a);
        else
        return 0;
    }
    for(int i=0; i<t; i++)
    {
        cout<<fixed<<setprecision(2);
        cout<<tx[i]->compute()<<endl;
        delete tx[i];
    }
}