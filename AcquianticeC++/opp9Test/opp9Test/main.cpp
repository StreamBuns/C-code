//
//  main.cpp
//  opp9Test
//
//  Created by 赵桐 on 2019/6/28.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include <cstdbool>
using namespace std;

class Shape
{
public:
    
    virtual double Area() = 0;
    virtual void Show() =0;
    virtual~Shape(){};
    virtual bool operator==(Shape & p1)
    {
        if (Area() == p1.Area())
            return true;
        else return false;
    }
    virtual bool operator> (Shape & p1)
    {
        if (Area() > p1.Area())
            return true;
        else return false;
    }
    virtual bool operator< (Shape & p1)
    {
        if (Area() < p1.Area())
            return true;
        else return false;
    }
};

class Rectangle : public Shape
{
protected:
    double rectWidth;
    double rectHeigh;
public:
    virtual double Area() = 0;
    virtual void Show() =0;
};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    
   //cout << "Hello, World!\n";
    return 0;
}
