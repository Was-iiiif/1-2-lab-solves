/*
Write a program using multilevel inheritance where Currency -> Dollar -> BDT.
Demonstrate conversion from Dollar to double (value in BDT),
ans also implement a constructor to allow conversion from int into Dollar object.
*/

#include <iostream>
using namespace std;

const double rate = 121.72; // suppose 1 USD = 121.72 BDT

class Currency {
protected:
    double value; // in USD
public:
    Currency(double v) : value(v) {}
};

class Dollar : public Currency {
public:
    Dollar(double d) : Currency(d) {}
    Dollar(int d) : Currency(d) {} // conversion constructor

    operator double() const {
        return value * rate;
    }

    void display() {
        cout << value << " Dollar" << endl;
    }
};

class BDT : public Dollar {
    double bdt;
public:
    BDT(double bdt) : Dollar(bdt / rate) , bdt(bdt) {}

    void display() {
        cout << bdt << " BDT" << endl;
    }
};

int main() {
    Dollar d = 5; // conversion constructor
    d.display();

    BDT taka(10);    // 10 tk
    taka.display();

    cout << "Amount in BDT = " << (double)d << endl;

    return 0;
}

