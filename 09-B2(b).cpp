/*Write a program that takes an integer N, then reads N product purchase records, where each record contains a product name and a quantity purchased.
Use a suitable container to store the products in such a way that repeated entries of the same product are accumulated into a single total.
After processing all records, print the products along with their total quantities in sorted order based on the product names.
Also display the product that has the highest total quantity purchased.*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    map<string, int>m;
    for(int i=0; i<N; i++)
    {
        string name;
        int quantity;
        cin>>name>>quantity;
        m[name]+=quantity;
    }
    for(auto x:m)
    {
        cout<<x.first<<"=="<<x.second<<endl;
    }
    cout<<"Highest quantity:\n";
    int highest=0;
    string hname;
    for(auto x:m)
    {
        if(x.second>highest)
            hname=x.first;
    }
    cout<<hname<<endl;
}
