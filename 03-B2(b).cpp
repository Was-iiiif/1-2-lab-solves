#include <iostream>
using namespace std;

/*
2. Create a custom MyString class (similar to std::string) using dynamic memory.
This problem requires the creation of a MyString class, similar to std::string, using dynamic memory, with the following specifications:
    1. Constructor: Allocates memory for the string.
    2. +: To concatenate two strings.
    3. ==: To compare two strings.
    4. []: To access a character at a given index.
    5. Output Operator: Overload the << operator to print the string.

Restriction : can't use C++ string, must take input in constructor
*/

class MyString {
public:
    int sz = 0;
    char *str;

    MyString(int take_input = true) {
        if (!take_input) {
            str = new(nothrow) char[1000];
            if (str == NULL) {
                cout << "Couldn't allocate memory.\n";
                exit(EXIT_FAILURE);
            }
        }
        else {
            char s[1000];
            cin >> s;
            while (s[sz] != '\0') sz++;

            str = new(nothrow) char[sz];
            if (str == NULL) {
                cout << "Couldn't allocate memory.\n";
                exit(EXIT_FAILURE);
            }
            for (int i = 0; i < sz; i++) str[i] = s[i];
        }
    }

    ~MyString() {
        delete[] str;
    }

    MyString operator + (const MyString &s) const {
        MyString temp(false);
        for (int i = 0; i < sz; i++) temp.str[i] = str[i];
        for (int i = sz; i < sz + s.sz; i++) temp.str[i] = s.str[i - sz];
        temp.sz = sz + s.sz;
        return temp;
    }

    bool operator == (const MyString &s) const {
        if (sz != s.sz) return false;

        for (int i = 0; i < sz; i++) {
            if (str[i] != s.str[i]) return false;
        }

        return true;
    }

    char& operator [] (int idx) {
        if (idx < 0 || idx >= sz) {
            static char err = '\0';
            cout << "Out of bound";
            return err;
        }
        else return str[idx];
    }

    friend ostream& operator<<(ostream &out, const MyString &s);
};

ostream& operator << (ostream& out, const MyString &s) {
    for (int i = 0; i < s.sz; i++) cout << s.str[i];
    return out;
}

int main() {
    MyString s1, s2, s3; // give s1 == s2 or s1 == s3, but not both

    cout << "s1[-1] = " << s1[-1] << endl;
    cout << "s1[0] = " << s1[0] << endl;
    cout << "s1[300] = " << s1[300] << endl;

    if (s1 == s2) cout << "Equal.\n";
    else cout << "Not equal.\n";

    if (s1 == s3) cout << "Equal.\n";
    else cout << "Not equal.\n";

    cout << s1 + s2 << endl;
    return 0;
}
