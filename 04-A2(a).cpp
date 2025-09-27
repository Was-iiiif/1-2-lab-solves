/*Define a base class Account and a derived class SavingsAccount. Demonstrate single inheritance and implement a conversion operator to convert a SavingsAccount object into a double representing the balance*/

#include<bits/stdc++.h>
using namespace std;
class Account{
protected:
    string name;
    string occupation;
public:
    Account(string a, string b):name(a), occupation(b)
    {
        cout<<"Account created"<<endl;
    }
};
class SavingsAccount: public Account{
protected:
    double balance;
public:
    SavingsAccount(string a, string b, double c):Account(a,b), balance(c){}
    operator double()
    {
        return balance;
    }
    void display()
    {
        cout<<"Personal Info: "<<endl<<name<<endl<<occupation<<endl;
    }
};
int main()
{
    string a,b;
    double c;
    cout<<"Enter name, occupation and balance: "<<endl;
    cin>>a>>b>>c;
    SavingsAccount s(a,b,c);
    s.display();
    cout<<"Account balance: "<<double(s)<<endl;

}
