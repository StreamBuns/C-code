//
//  main.cpp
//  opp7Test
//
//  Created by 赵桐 on 2019/6/14.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    double x,y;
public:
    Point(double _x = 0 ,double _y = 0):x(_x),y(_y){}
    double GetX()const {return x;};
    double GetY()const {return y;};
    void SetX(double _x)
    {
        x = _x;
    }
    void SetY(double _y)
    {
        y = _y;
    }
   Point  operator + (Point & lp)
    {
        Point temp;
        temp.x = x + lp.x;
        temp.y = y + lp.y;
        return  temp;
    }
};
class Line
{
    Point p1;
    Point p2;
public:
    Line(const Point & lp1,const Point & lp2)
    {
        p1.SetX(lp1.GetX());
        p1.SetY(lp1.GetY());
        p2.SetX(lp2.GetX());
        p2.SetY(lp2.GetY());
    }
    
    void Printf()
    {
        cout <<p1.GetX() << " " <<p1.GetY()<<endl;
        cout <<p2.GetX() << " " <<p2.GetY()<<endl;
    }
    double Length () {
        return
    sqrt((p1.GetX()-p2.GetX())*(p1.GetX()-p2.GetX())+(p1.GetY()-p2.GetY())*(p1.GetY() - p2.GetY()));
    }
};
class Triangle
{
    Point p1;
    Point p2;
    Point p3;
public:
    Triangle(const Point &_p1,const Point &_p2,const Point &_p3):p1(_p1),p2(_p2),p3(_p3){}
    double Grith()
    {
        Line l1(p1,p2),l2(p1,p3),l3(p2,p3);
        return l1.Length()+l2.Length()+l3.Length();
    }
    double Area()
    {
        Line l1(p1,p2),l2(p1,p3),l3(p2,p3);
        double q = Grith()/2;
        return sqrt(q*(q-l1.Length())*(q-l2.Length())*(q-l3.Length()));
    }
};
void Run();
int main(int argc, const char * argv[]) {
    // insert code here...
//    Point  P1(0,3.0);
//    Point  P2(4.0,0);
//    Point  P3 (0,0);
//    Triangle l1(P3,P1,P2);
//   // l1.Printf();
//  cout << l1.Area() <<endl;
    Run();
    return 0;
}
void Run()
{
    double x1,x2,x3,y1,y2,y3;
    cin >> x1>>y1>>x2>>y2>>x3>>y3;
    Point  P1(x1,y1);
    Point  P2(x2,y2);
    Point  P3 (x3,y3);
    Triangle T1(P3,P1,P2);
    // l1.Printf();
    cout << T1.Grith()<<" "<<T1.Area() <<endl;
}
