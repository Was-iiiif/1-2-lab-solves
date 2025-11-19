/*2. Write a program that reads an integer N, then reads N movie rating entries, each containing a movie name and a rating (integer).
Store these entries in a vector<pair<string,int>> and display them in the order they were entered.
Then, using a suitable container, find all distinct ratings, print them in sorted order, and finally display the number of movies that received the lowest rating.*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    cin.ignore();
    vector<pair<string,int>>v;
    for(int i=0; i<N; i++)
    {
        string name;
        int rating;
        getline(cin,name);
        cin>>rating;
        cin.ignore();
        v.push_back({name,rating});
    }
    for(const auto&m:v)
    {
        cout<<m.first<<"=="<<m.second<<endl;
    }
    set<int>rate;
    for(const auto&c:v)
    {
        rate.insert(c.second);
    }
    cout<<"Ratings: "<<endl;
    for(const auto&c:rate)
    {
        cout<<c<<endl;
    }
    int count=0;
    int low=100000;
    for(const auto&c:rate)
    {
        if(c<low)
        {
            low=c;
        }
    }
    for(const auto&c:v)
    {
        if(c.second==low)
        {
            count++;
        }
    }
    cout<<"Num of movies with lowest rating: "<<count<<endl;




}
