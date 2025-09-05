/*
Write a C++ program using concepts of class and objects
-Define a class "Point" that represents a point in a 2D plane
-Each point has two co-ordinates : x and y (Private member)
-Use a member function to to set the values of x and y
-Write a function to calculate the area of the triangle
The program should read three points from the user, create three "Point" objects and display the area.

Input :
Enter coordinates of first point : 0 0
Enter coordinates of second point : 4 0
Enter coordinates of third point : 0 3

Output :
Points of Triangle :
P1(0, 0), P2(4, 0), P3(0, 3)
Area of Triangle = 6.00
*/
#include <bits/stdc++.h>
using namespace std;

class point{
    double x,y;
    public:
    void set_val(double a, double b){
        x=a;
        y=b;
    }
    double getx(){
        return x;
    }
    double gety(){
        return y;
    }


};
void area(point&p1, point&p2, point&p3)
{
    cout<<abs(0.5*(p1.getx()*p2.gety()+ p2.getx()*p3.gety()+p3.getx()*p1.gety()-p1.getx()*p3.gety()-p3.getx()*p2.gety()-p2.getx()*p1.gety()));
}

int main() {
    point p1, p2, p3;
    double a,b, c, d, e, f;
    cout<<"Enter coordinates of first point:";
    cin>>a>>b;
    cout<<"Enter coordinates of second point:";
    cin>>c>>d;
	cout<<"Enter coordinates of third point:";
    cin>>e>>f;
    p1.set_val(a,b);
    p2.set_val(c,d);
    p3.set_val(e,f);
    cout<<"Points of the triangle:"<<endl;
    printf("p1(%.2f, %.2f),p2(%.2f, %.2f),p3(%.2f, %.2f) ", a,b,c,d,e,f);
    cout<<"The area is: ";
    cout<<fixed<<setprecision(2);
    area(p1, p2, p3);

}