//
//  main.cpp
//  opp4Test
//
//  Created by 赵桐 on 2019/6/13.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
using namespace std;

 const double p  = 3.1415926;
class Cylinder
{
    double height;
    double radius;
public:
 
    
    Cylinder (double _h = 0.0 , double _r = 0.0):height(_h),radius(_r){};
    
    double GetHeight()const{return height;};
    double GetPI()const{return p;};
    double GetRadius()const{return radius;};
    
    void SetHeight (double _h){height = _h;};
    void SetRadius (double _r){radius = _r;};
    
    double Volume()
    {
        return p * radius * radius * height ;
    }
    double Area()
    {
        return (2 * p * radius * height + p * radius *radius*2);
    }
    
};
void Run();
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
     Run();
    return 0;
}
void Run()
{
    double h = 0.0 , r = 0.0 ;
    cin >> h >> r;
    Cylinder  cy_1(h,r);
    cout << "pi=" << cy_1.GetPI() << ", "
    << "height=" << cy_1.GetHeight() << ", "
    << "radius=" << cy_1.GetRadius() << ":"
    << "volume=" << cy_1.Volume() << ", "
    << "area=" << cy_1.Area() <<endl;
}
