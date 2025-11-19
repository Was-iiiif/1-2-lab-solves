/*1. Write a program that takes an integer N, then reads N customer purchase records, each containing a customer name and the amount spent.
Use a suitable STL container to calculate the total amount spent by each customer.
After processing all records, print the list of customers and their total spending in sorted order. Finally, display the customer who spent the highest total amount.*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    cin.ignore();
    map<string,double>m;
    for(int i=0; i<N; i++)
    {
        string name;
        double amount;
        getline(cin,name);
        cin>>amount;
        cin.ignore();
        m[name]+=amount;
    }
    for(const auto&c:m)
    {
        cout<<c.first<<" == "<<c.second<<endl;
    }
    string highName;
    double highPrice=0;
    for(const auto&p:m)
    {
        if(p.second>highPrice)
        {
            highPrice=p.second;
            highName=p.first;

        }
    }
    cout<<"Highest: "<<highName<<" == "<<highPrice<<endl;

}
