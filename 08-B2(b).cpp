/*2. Create a class template Counter<T> that counts how many objects of a particular type T have been created using static members. Instantiate it with int and double and print their counts separately.
Input: N as the total number of int and double objects to create. The following N lines will take input specifying either “Integer” or “Double”, indicating the type of objects to create.
Output: Two integers showing object counts for int and double types.
Example:
Input:3
Integer
Double
Integer
Output:
2 1
*/

#include<bits/stdc++.h>
using namespace std;
template<class T>
class Counter{
public:
    static int c1;
};
template<class T>
int Counter<T>::c1=0;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        if(s=="Integer")
            Counter<int>::c1++;
        else if(s=="Double")
            Counter<double>::c1++;
    }
    cout<<Counter<int>::c1<<" "<<Counter<double>::c1<<endl;
}
