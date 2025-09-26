/*
Create a base class Distance and a derived class MeterCentimeter.
Demonstrate single inheritance, and implement a conversion operator that
converts a MeterCentimeter object into a double representing total meters.


For these problems, the variables may vary from person to person, as it's ambiguous.
*/

#include <bits/stdc++.h>
using namespace std;

class Distance {
protected :
    double dis;
public :
    Distance(double dis) : dis(dis) {}
};

class MeterCentimeter : public Distance{
protected :
    int m, cm;

public :
    MeterCentimeter(int m, int cm) : Distance(m + cm/100.00), m(m), cm(cm) {}

    operator double() const {
        return dis;
    }
};

int main() {
    MeterCentimeter mcm(5, 11);

    cout << (double)mcm << endl;
}
