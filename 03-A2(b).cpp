/*Create a MySet class that represents a mathematical set of integers.

Internally store elements in a dynamic array (no STL). Ensure uniqueness (no duplicates allowed). Overload following operators:
➢ + → union of two sets.
➢ = → deep copy assignment.

Overload the << operator to print the set in {a, b, c} format.

In main(), input two sets, perform union, and assignment.
SOLVED BY SHUVO 2307106*/

#include <bits/stdc++.h>
using namespace std;

const int N = 10007;

class MySet {
public:
    int *arr;
    int sz;

    MySet(int n) {
        if (n < 0) {
            cout << "How do you even imagine this???\n";
            exit(EXIT_FAILURE);
        }

        arr = new int[N];
        sz = 0;
        for (int i = 0; i < N; i++) arr[i] = 0;

        if (n) {
            cout << "Enter " << n << " elements : ";
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                if (arr[x] == 0) {
                    arr[x] = 1;
                    sz++;
                }
            }
        }
    }

    MySet& operator=(const MySet &other) {
        if (this != &other) {
            delete[] arr;
            arr = new int[N];
            sz = other.sz;
            for (int i = 0; i < N; i++) arr[i] = other.arr[i];
        }
        return *this;
    }

    MySet operator+(const MySet &other) const {
        MySet temp(0);
        temp.sz = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] == 1 || other.arr[i] == 1) {
                temp.arr[i] = 1;
                temp.sz++;
            }
        }
        return temp;
    }

    ~MySet() {
        delete[] arr;
    }

    friend ostream& operator<<(ostream &out, const MySet &s);
};

ostream& operator<<(ostream &out, const MySet &s) {
    if (s.sz == 0) {
        out << "{ phi }";
    }
    else {
        out << "{ ";
        for (int i = 0, cnt = 0; i < N; i++) {
            if (s.arr[i] == 1) {
                out << i;
                cnt++;
                if (cnt < s.sz) out << ", ";
            }
        }
        out << " }";
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    MySet s1(n);

    int m;
    cin >> m;
    MySet s2(m);

    cout << "S1 = " << s1 << endl;
    cout << "S2 = " << s2 << endl;

    MySet s3 = s1 + s2;
    cout << "S1 + S2 = " << s3 << endl;

    MySet s4 = s2;
    cout << "S4 = " << s4 << endl;

    return 0;
}
```
