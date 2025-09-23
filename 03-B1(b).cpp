/*Create a Date class that represents a calendar date (day, month, year).

Constructor initializes date. Must validate date (e.g., 30 Feb → invalid). Must handle leap years. Overload following operators:
➢ +, - → add and difference two dates.
➢ == → check if two dates are the same.
➢ = → deep copy assignment.
➢ << → print in DD/MM/YYYY format.

In main(), input two dates, perform operations.*/

#include <bits/stdc++.h>
using namespace std;

class Date {
    int day, month, year;
    bool LeapYear(int y)  
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
    int daysInMonth(int m, int y)  
    {
        if (m == 2) return LeapYear(y) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }
    bool ValidDate(int d, int m, int y)  
    {
        if (y < 1 || m < 1 || m > 12 || d < 1 || d > daysInMonth(m, y)) return false;
        return true;
    }

public:
    Date(int d = 1, int m = 1, int y = 2000) 
    {
        if (isValidDate(d, m, y)) 
        {
            day = d; month = m; year = y;
        } 
        else 
        {
            cout << "Invalid date"<<endl;
            day = 1; month = 1; year = 2000;
        }
    }
    Date& operator=( Date &d) {
        if (this != &d) {
            day = d.day;
            month = d.month;
            year = d.year;
        }
        return *this;
    }
    bool operator==( Date &d)  
    {
        return (day == d.day && month == d.month && year == d.year);
    }
    Date operator+( Date &dt)  
    {
        int d = day + dt.day;
        int m = month + dt.month;
        int y = year + dt.year;
        if(m > 12) 
        { 
          m %= 12; 
          y=y+m/12; 
        }
        if(d > daysInMonth(m, y)) 
        {
            d %= daysInMonth(m, y);
            m=m+d/daysInMonth(m, y);
            if (m > 12) 
            { 
              m = 1; 
              y++; 
            }
        }
        return Date(d, m, y);
    }

    int operator-(Date &other)  
        int totald1=0;
        int totald2=0;
        for(int i=1; i<=year; i++)
            totald1+= (LeapYear(i) ? 366 : 365);
        for(int i=1; i<=dt.year; i++)
            totald2+= (LeapYear(i) ? 366 : 365);
        for(int i=1; i<=month; i++)
            totald1+=daysInMonth(month,year);
        for(int i=1; i<=dt.month; i++)
            totald2+=daysInMonth(dt.month,dt.year);
        totald1+=day;
        totald2+=dt.day;
        return abs(totald1-totald2); 
}
    friend ostream& operator<<(ostream &output, Date &d) {
        output << setfill('0') << setw(2) << d.day << "/"
            << setw(2) << d.month << "/"
            << setw(4) << d.year;
        return output;
    }
};

int main() {
    int d1, m1, y1, d2, m2, y2;
    cout << "Enter first date (DD MM YYYY): ";
    cin >> d1 >> m1 >> y1;
    cout << "Enter second date (DD MM YYYY): ";
    cin >> d2 >> m2 >> y2;
    Date dt1(d1, m1, y1);
    Date dt2(d2, m2, y2);
    cout << "Date 1: " << dt1 << endl;
    cout << "Date 2: " << dt2 << endl;
    if (dt1 == dt2)
        cout << "Dates are equal.\n";
    else
        cout << "Dates are not equal.\n";
    Date sum= dt1 + dt2;
    cout << "SUM: " << sum << endl;
    int diff = dt1 - dt2;
    cout << "Difference: " << diff << " days\n";
    Date dt3;
    dt3 = dt1;
    cout << "Deep copy of dt1: " << dt3 << endl;

    return 0;
}
