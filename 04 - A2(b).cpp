/*
Create a multilevel inheritance Number -> Rational -> Fraction.
Demonstrate conversion by allowing
    i. implicit conversion from int to Fraction object
    ii. conversion operator from Fraction to double for decimal form
*/

#include <iostream>
using namespace std;

class Number {
protected :
    double num;
public :
    Number (double val) : num(val) {}
};

class Rational : public Number{
public :
    Rational(double x, double y) : Number(x / y) {}
};

class Fraction : public Rational {
    double nom, denom;
public :
    Fraction(int x, int y) : Rational(x, y), nom(x), denom(y) {
        if (y == 0) {
            cout << "Fraction not valid.\n";
            exit(EXIT_FAILURE);
        }
    }

    Fraction (int x) : Rational((double)x, 1.00), nom(x), denom(1) {}

    operator double() const {
        return num;
    }

    void display() {
        cout << nom << " / " << denom << endl;
    }
};

int main() {
    Fraction f(1, 8);
    f.display();

    Fraction f2 = 0;
    f2.display();

    cout << (double)f << endl;
    return 0;
}

