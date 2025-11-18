/*1. Write a templated function maxValue() that returns the larger of two given values for any type, but for strings (std::string), it should return the lexicographically smaller one.
Input: Two space-separated values (could be int, float, or string).
Output: A single value following the specialization rule.
Example:
Input: apple banana → Output: apple*/

#include <iostream>
#include <string>
using namespace std;
template <class T>
T maxValue(T a, T b)
{
    return (a > b) ? a : b;
}
template <>
string maxValue<string>(string a, string b)
{
    return (a < b) ? a : b;
}

int main() {
    string a, b;
    cin >> a >> b;


    if (isdigit(a[0])) {
        cout << maxValue(stod(a), stod(b));
    } else {
        cout << maxValue(a, b);
    }

    return 0;
}
