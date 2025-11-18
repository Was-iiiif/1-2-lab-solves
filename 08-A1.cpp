/*Design a templated class Sorter<T, Policy> that sorts an array of type T according to a policy defined by Policy. 
The Policy class should define a static function compare(T a, T b) returning true if a should come before b. 
Implement two comparison policies — one for ascending order and another for descending order. 
The program should take the size of the array, the array elements, and a policy type (asc or desc), then output the sorted array.
Input:
First line: integer N (size of the array)
Second line: N integers
Third line: sorting policy type (asc or desc)
Output:
Sorted array according to the selected policy.*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
template<class T>
class Ascending{
    public:
    static bool compare(T a, T b) 
    {
        return a<b;
    }
};
template<class T>
class Descending{
    public:
    static bool compare(T a, T b) 
    {
        return a>b;
    }
};
template<class T, class Policy>
class Sorter{
    public:
    void sort(T arr[], int n)
    {
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(!Policy::compare(arr[i], arr[j]))
                {
                    T temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
    }
};
int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; i++)
    {
        cin>>arr[i];
    }
    string type;
    cin>>type;
    if(type=="asc")
    {
        Sorter<int,Ascending<int>>s;
        s.sort(arr,N);
    }
    else if(type=="desc")
    {
        Sorter<int,Descending<int>>s;
        s.sort(arr,N);
    } 
    for(int i=0; i<N; i++)
    cout<<arr[i]<<" ";   
}
