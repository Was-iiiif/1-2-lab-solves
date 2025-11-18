#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<int, string>m1;
    map<int, string>m2={
        {1,"KUET"},
        {2,"CSE"},
        {3, "2K23"}};
cout<<m2[1]<<endl;
cout<<m2.at(2)<<endl;
m2.insert({4,"Hello"});
cout<<m2.at(4)<<endl;
m2.at(4)="World";
auto it=m2.find(2);
if(it!=m2.end())
    cout<<it->first<<" "<<it->second<<endl;
else
    cout<<"Key not found";
for(auto it=m2.begin();it!=m2.end(); it++)
    cout<<it->first<<" "<<it->second<<endl;
return 0;

}
