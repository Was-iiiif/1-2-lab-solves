/*1. Write a class template Pair<T> with two attributes first and second.
Implement two constructors — one taking two arguments of type T, and another taking a single integer that initializes both attributes to that value if T is numeric or to 'X' if T is char.
Overload the * operator: for numeric types, it should multiply the two attributes; for char, it should return their concatenation as a string.
Input: Type (int or char)
Output: The result of the * operation.*/

#include<iostream>
#include<string>
using namespace std;
template<class T>
class Pair{
public:
    T first;
    T second;
    Pair(T a, T b):first(a), second(b){}
    Pair(int val);
    auto operator *();
};
template<>
Pair<int>::Pair(int val)
{
    first=val;
    second=val;
}
template<>
auto Pair<int>:: operator*()
{
    return first*second;
}
template<>
Pair<char>::Pair(int val)
{
    first='X';
    second='X';
}
template<>
auto Pair<char>::operator*()
{
    string temp;
    temp+=first;
    temp+=second;
    return temp;
}
int main()
{
    string s;
    cin>>s;
    if(s=="int")
    {
        Pair<int>p1(4,5);
        cout<<*p1<<endl;
    }
    else if(s=="char")
    {
        Pair<char>p2(5);
        cout<<*p2<<endl;
    }
}
