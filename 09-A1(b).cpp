/*2. Write a program that takes an integer N, then reads N book purchase entries, each containing a book title and a price.
Use a suitable container to maintain the total price collected per book title.
After processing, print the list of books and total amounts in sorted order. Then also print the book with the least total amount spent.*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    map<string, double>m;
    for(int i=0; i<n; i++)
    {
        string title;
        double price;
        getline(cin,title);
        cin>>price;
        cin.ignore();
        m[title]+=price;
    }
    for(const auto&b:m )
    {
        cout<<b.first<<"=="<<b.second<<endl;
    }
    string mintitle;
    double minprice=10000000;
    for(const auto&p:m)
    {
        if(p.second<minprice)
        {
            minprice=p.second;
            mintitle=p.first;
        }
    }
    cout<<"Lowest price: "<<mintitle<<"=="<<minprice<<endl;

}
