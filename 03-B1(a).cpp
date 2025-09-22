/*Create a Rational class that represents fractions (numerator/denominator).
Constructor initializes numerator and denominator. Must reduce fraction to simplest form (4/8 → 1/2). Must handle invalid denominator (like 0). Overload following operators:
➢ +, / → add and divide two rational numbers.
➢ == → check equality (after reduction).
➢ = → deep copy assignment.
➢ << → print in reduced form (e.g., 3/4).
In main(), input two rationals, perform arithmetic, check equality, and assignment.*/


#include<bits/stdc++.h>
using namespace std;

class Rational{
    int numerator;
    int denominator;
public:
    void reduce()
    {
        if(denominator==0)
        {
            cout<<"Error"<<endl;
            numerator=0;
            denominator=1;
        }
        if(denominator<0)
        {
            denominator=-denominator;
            numerator=-numerator;
        }
        int g=__gcd(abs(numerator),denominator);
        numerator/=g;
        denominator/=g;
    }
    Rational(int a=0, int b=1)
    {
        numerator=a;
        denominator=b;
        reduce();
    }
    Rational &operator=(Rational &r)
    {
        denominator=r.denominator;
        numerator=r.numerator;
        return *this;
    }
    Rational operator +(Rational &r)
    {
        Rational temp(0,1);
        temp.numerator= denominator*r.numerator+r.denominator*numerator;
        temp.denominator=denominator*r.denominator;
        temp.reduce();
        return temp;
    }
    Rational operator /(Rational &r)
    {
        Rational temp(0,1);
        temp.numerator=numerator*r.denominator;
        temp.denominator=denominator*r.numerator;
        temp.reduce();
        return temp;
    }
    Rational& operator=(const Rational& other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }
    bool operator ==(Rational &r)
    {
        return numerator==r.numerator && denominator==r.denominator;
    }
    friend ostream &operator <<(ostream &, Rational&);
};
ostream &operator <<(ostream &output, Rational&r)
{
    output<<r.numerator<<"/"<<r.denominator<<endl;
    return output;
}
int main()
{
    Rational r1(16,25);
    Rational r2(9,25);
    Rational r3=r1+r2;
    Rational r4=r1/r2;
    Rational r5=r3;
    cout<<"Fraction 01: "<<r1<<"Fraction 02:"<<r2<<"Sum: "<<r3<<"Div: "<<r4<<"Deep copy of r3: "<<r5;

}
