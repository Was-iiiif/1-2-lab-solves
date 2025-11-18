/*2. Design a templated base class Measure that stores a single attribute value and provides a constructor to initialize it.
Derive a class Distance from Measure that overloads the + operator to add two Distance objects.
The behavior of + should differ by type:
If T is an integer, the sum should return the total in meters directly.
If T is a floating-point, the result should be formatted as kilometers (i.e., divide the sum by 1000).
Provide a show() function to display the result with an appropriate unit (m or km).
Input: Two distance values (both integers or both floating-point).
Output: The result after performing the + operation*/

#include <iostream>
#include <string>
using namespace std;
template<class T>
class Measure {
public:
    T value;
    Measure(T a = 0) : value(a) {}
};
template<class T>
class Distance : public Measure<T> {
public:
    Distance(T a = 0) : Measure<T>(a) {}
    Distance operator+(Distance &d);
    void show();
};
template<>
Distance<int> Distance<int>::operator+(Distance<int> &d) {
    return Distance<int>(value + d.value);
}
template<>
void Distance<int>::show() {
    cout << value << " m" << endl;
}
template<>
Distance<float> Distance<float>::operator+(Distance<float> &d) {
    return Distance<float>((value + d.value) / 1000.0f);
}

template<>
void Distance<float>::show() {
    cout <<value << " km" << endl;
}

int main() {
    string a, b;
    cin >> a >> b;
    int flag=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]=='.')
        {
            flag=1;
            break;
        }
    }
    if (flag==1) {
        float x = stof(a);
        float y = stof(b);
        Distance<float> d1(x);
        Distance<float> d2(y);
        Distance<float> result = d1 + d2;
        result.show();
    }
    else {
        int x = stoi(a);
        int y = stoi(b);
        Distance<int> d1(x);
        Distance<int> d2(y);
        Distance<int> result = d1 + d2;
        result.show();
    }

    return 0;
}
