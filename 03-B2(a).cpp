/*Create a Polynomial class in C++ (degree n):
Constructor dynamically allocates an array to store coefficients.
Overload following operators:
    ➢ +, - → to add and subtract two polynomials.
    ➢ [] → to access or modify the coefficient of a given degree.
    • Overload the << operator to print the polynomial in standard form (e.g., 3x^2 + 2x + 1).
    • In main(), demonstrate polynomial addition, subtraction, coefficient modification using [], and assignment.*/


#include<iostream>
using namespace std;
class Polynomial{
    int degree;
    int *coeff;
public:
    Polynomial(int d)
    {
        degree=d;
        coeff=new int[degree+1];
        for(int i=0; i<=degree; i++)
            coeff[i]=0;
    }
    Polynomial(){}
    ~Polynomial()
    {
        delete[] coeff;
    }
    int &operator [](int deg)
    {
        if(deg<0 || deg>degree)
        {
            cout<<"Error"<<endl;
            exit(1);
        }
        return coeff[deg];
    }
    Polynomial operator +(const Polynomial &p)
    {
        int max_deg = (degree >= p.degree) ? degree : p.degree;
        Polynomial result(max_deg);
        for(int i=0; i<=max_deg; i++)
        {
            int c1=(i<=degree)?coeff[i]:0;
            int c2=(i<=p.degree)?p.coeff[i]:0;
            result.coeff[i]=c1+c2;
        }
        return result;
    }
    Polynomial operator -(Polynomial &p)
    {
        int max_deg = (degree >= p.degree) ? degree : p.degree;
        Polynomial result(max_deg);
        for(int i=0; i<=max_deg; i++)
        {
            int c1=(i<=degree)?coeff[i]:0;
            int c2=(i<=p.degree)?p.coeff[i]:0;
            result.coeff[i]=c1-c2;
        }
        return result;
    }
    friend ostream &operator<<(ostream &, Polynomial &);
};

ostream &operator<<(ostream &output, Polynomial &p)
{
    for(int i=p.degree; i>=0; i--)
    {
        output<<p.coeff[i];
        if(i>0)
            output<<"x^"<<i<<"+";
    }
    return output;
}
int main()
{
    Polynomial p1(3);
    Polynomial p2(3);
    p1[2]=3;    p1[1]=2;    p1[0]=1;
    p2[2]=1;    p2[1]=4;    p2[0]=5;
    cout<<p1<<endl;
    cout<<p2<<endl;
    Polynomial p3=p1+p2;
    Polynomial p4=p1-p2;
    cout<<"SUM: "<<p3<<endl;
    cout<<"DIFF: "<<p4<<endl;
    p1[0]=100;
    cout<<"Modified p1: "<<p1<<endl;
}

