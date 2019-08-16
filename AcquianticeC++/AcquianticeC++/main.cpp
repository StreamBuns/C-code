//
//  main.cpp
//  AcquianticeC++
//
//  Created by 赵桐 on 2019/4/28.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>

using namespace std;
# define M 5
template <class _T>
_T add (_T _r, _T _l)
{
    return _r + _l;
}
//template <class _T>
//class intArr
//{
//private:
//    _T * h;
//public:
//
//};
class Fraction
{
    int up;
    int down;
public:
    Fraction(int _u = 1,int _d = 1)
    {
        up = _u;
        down = _d;
    }
    friend istream &operator >> (istream & in,Fraction & f1)
    {
        in >> f1.up >> f1.down;
        return in;
    }
friend ostream &operator << (ostream & out ,Fraction f1)
    {
        out << f1.up << "/"<<f1.down <<endl;
        return out ;
    }
};

class A
{
    int x;
public:
    A()
    {
        x = 0;
    }
    virtual  ~A()
    {
        
    }
};
class Complex
{
    double r;
    double i;
public:
    Complex(double _r = 0,double _i = 0)
    {
        r = _r;
        i = _i;
    }
    Complex(Complex & c1)
    {
        r = c1.r;
        i = c1.i;
    }
    friend istream & operator >>(istream & in , Complex & c1)
    {
        in >> c1.r >> c1.i;
        return in;
    }
    friend ostream & operator <<(ostream & out , Complex & c1)
    {
        out << c1.r <<"/"<< c1.i<<endl;
        return out;
    }
   friend Complex operator + (Complex & c1,Complex c2)
    {
//        Complex temp(c1.i+c2.i);
        Complex temp((c1.r+c2.r),(c1.i+c2.i));
        return temp;
    }
//    Complex operator + (const Complex & c1)
//    {
//        return Complex temp((c1.r+r),(c1.i+i));
//    }
    Complex & operator - ()
    {
        r = -r;
        i = -i;
        return *this;
    }
    Complex & operator = (const Complex & r1)
    {
        this->r = r1.r;
        this->i = r1.i;
        return *this;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    delete <#expression#>
//    Complex c1(1,1),c2(2,2);
//    Complex c3(c1);
////    c3 = c1 + c2;
//    cout << -c3;
//    cout << sizeof(A)<<endl;
//    Fraction f1;
//    cin >> f1;
//    cout<< f1;
    //cout <<add(1.1,1.1);
//    const int i = 100;
//    constexpr int u = 100;
//    auto p = 2;
//    decltype(p) x = 2;
//    decltype(x) t = 2;
//    decltype(t) b = 2;
//    unsigned char u = -1;
//    int  i = u;
//    cout << sizeof(char) << endl;
//    cout << i << endl;
//    cout << true << "\t" << false << endl;
//
//    cout << boolalpha << true << "\n" << false << endl;
//    cout << noboolalpha;
//    cout << true << "\t" << false;
    
    //char Name [20]={'\0'};
//    int i;
//    for ( i = 0; i < 20 ;i++ )
//    {
//        Name[i] = cin.get() ;
//        if (Name[i] == '\n')
//            break;
//    }
//    for ( i = 0; i < 20 ;i++ )
//    {
//        cout.put(Name[i]);
//        if (Name[i] == '\n')
//            break;
//    }
////    int Number1 = 0,Number2 = 0;
//    cout <<"Enter two numbers: "<<endl;
//    cin  >> Number1 >> Number2;
//    cout << "The sum of " << Number1 << " and "<< Number2 <<" is "
//         << Number1 + Number2 << endl;
//    cout << "My name is Tony\n";
    return 0;
}
