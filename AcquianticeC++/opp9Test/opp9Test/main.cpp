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

#define PI 3.1415926
class Shape
{
public:
    
    virtual double Area() = 0;
    virtual void Show() =0;
    virtual~Shape(){};
    friend bool operator==(Shape & p1,Shape & p2)
    {
        if (p2.Area() == p1.Area())
            return true;
        else return false;
    }
    friend double operator - (Shape & p1 ,Shape & p2)
    {
        return p1.Area()*p1.Area()-p2.Area()*p2.Area();
    }
    friend bool operator> (Shape & p1,Shape & p2)
    {
        if (p1.Area() > p2.Area())
            return true;
        else return false;
    }
    friend bool operator< (Shape & p1,Shape & p2)
    {
        if (p1.Area() < p2.Area())
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
    Rectangle(double _w = 0,double _h = 0)
    {
        rectWidth = _w;
        rectHeigh = _h;
    }
    double Area()
    {
        return rectHeigh * rectWidth;
    }
    void Show()
    {
   cout << "W: "<<rectWidth<<"; H:"<<rectHeigh<<"; Area: "<<Area()<<endl;    }
};
class Ellipse : public Shape
{
protected:
    double rectWidth;
    double rectHeigh;
public:
    Ellipse(double _w = 0,double _h = 0)
    {
        rectWidth = _w;
        rectHeigh = _h;
    }
    void Show()
    {
        cout << "W: "<<rectWidth<<"; H:"<<rectHeigh<<"; Area: "<<Area()<<endl;
    }
    double Area()
    {
        return PI*(rectHeigh /2)* (rectWidth/2);
    }
};
void Run();
int main(int argc, const char * argv[]) {
    // insert code here...
    Run();
    
   //cout << "Hello, World!\n";
    return 0;
}
void Run()
{
    int shapeNumber;
    double width;
    double highth;
    string type;
    cin >> shapeNumber;
    Shape * shapeArr[shapeNumber];
//    shapeArr = new Shape[shapeNumber];
    
    
    
    for(int i=0;i<shapeNumber;i++)
    {
        cin >> type >> width >> highth;
        if(type == "R")
        {
            shapeArr[i] = new Rectangle(width,highth);
        }
        if(type == "E")
        {
            shapeArr[i] = new Ellipse(width,highth);
        }
    }
    //输入
    
    
    for (int i=0;i < shapeNumber ; i++)
    {
        shapeArr[i]->Show();
    }
    
    //输出原来的
    for (int i=0;i < shapeNumber;i++)
    {
        for (int j = i+1;j < shapeNumber;j++)
        {
            if(*shapeArr[i]>*shapeArr[j])
            {
            if ((*shapeArr[i]-*shapeArr[j])<0.00000001)
                cout << "Area of Shape["<<i<<"] is equal to Shape["<<j<<"]"<<endl;}
            else
            {
                if ((*shapeArr[j]-*shapeArr[i])<0.00000001)
                    cout << "Area of Shape["<<i<<"] is equal to Shape["<<j<<"]"<<endl;
            }
        }
    }
    
    //判断是否相等
    Shape * temp;
    for (int i=0;i < shapeNumber;i++)
    {
        for (int j = i+1;j < shapeNumber;j++)
        {
            if (*shapeArr[i] < *shapeArr[j])
            {
                temp = shapeArr[j];
                shapeArr[j] = shapeArr[i];
                shapeArr[i] = temp;
            }
        }
    }
    
    //排序
    
    for (int i=0;i < shapeNumber ; i++)
    {
        shapeArr[i]->Show();
    }
//    输出
    
}
