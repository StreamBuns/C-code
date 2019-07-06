//
//  main.cpp
//  opp11Test
//
//  Created by 赵桐 on 2019/7/3.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

//int CMM(int l ,int r);
void Swap(int *l ,int *r);

class Rational
{
    int iUp;
    int iDown;

    int Gcd(int x,int y)
    {
        int z = y;
        while(x%y!=0)
        {
            z = x%y;
            x = y;
            y = z;
        }
        return z;

//        int temp = r;
//        if (r > l)
//        {
//            Swap(&l, &r);
//        }
//        if (l ==0&&r==0)
//            return 1;
//        else{
//
//         while ( l%r!=0)
//        {
//            temp = l % r;
//            l = r;
//            //        if (a % (a%b) ==0)
//            r = temp;
//            if (r > l)
//            {
//                Swap(&l, &r);
//            }
//        }
//        return temp;
//        }
    }

    void Reduce()
    {
        int temp = iUp;
        iUp = iUp / Gcd(temp, iDown);
        iDown = iDown / Gcd(temp, iDown);
        if(iDown < 0)

        {
            iUp = -iUp;
            iDown = -iDown;
        }
    };
//    void Reduce(Rational & r1)
//    {
//
//    }


public:

    Rational(int _u = 1, int _d = 1)
    {
        iUp = _u;
        iDown = _d;
        Reduce();
    }
//    void Right()
//    {
//        if(iDown < 0)
//
//        {
//            iUp = -iUp;
//            iDown = -iDown;
//        }
//        Reduce();
//    }
    int GetUp(){return iUp;}
    int GetDowm(){return iDown;}
    void SetUp(int _u){iUp = _u;}
    void SetDown(int _d){iDown = _d;}
//        Rational& operator=(const Rational& a)
//        {
//            iUp=a.iUp;
//            iDown=a.iDown;
//            Reduce();
//            return *this;
//        }
    Rational & operator = (const  Rational & r1)
    {
//        if (this == &r1)
//            return *this;
        iUp = r1.iUp;
        iDown = r1.iDown;
        Reduce();
        //        SetUp(r1.GetUp());
        //        SetDown(r1.GetDowm());
        return *this;
    }
    //    //符值
//        Rational operator-()
//        {
//            Rational t;
//            t.iUp=-iUp;
//            t.iDown=iDown;
//            return t;
//        }
   Rational operator - ()
    {
        Rational temp;
        temp.iUp = -iUp;
        temp.iDown = iDown;
        temp.Reduce();
        return temp;
//     Rational _r;
//       _r.SetUp(-(r1.GetUp()));
//        _r.SetDown(-(r1.GetDowm()));
//       return _r;
//        r1.iUp = -r1.iUp;
//        return r1;
    }
//    //变成负数,无法进行2个数的计算

    Rational &operator ++()
    {
        iUp = iUp + iDown;
//        temp.iUp = iUp + iDown;
        this->Reduce();
        return *this;
    }
    //前置++ 例如 ++i运算之前+1；
    Rational operator ++(int )
    {
        Rational ex(iUp,iDown);
        iUp = iUp + iDown;
        Reduce();
        return ex;

    }
    //后置++ 例如i++运算完成之后+1；

    Rational& operator --()
    {
        iUp =  iUp - iDown;
       this->Reduce();

        return *this;
    }
    //前置--
    Rational operator --(int)
    {
        Rational temp (iUp,iDown);
        iUp = iUp - iDown;

        Reduce();
//        temp.Reduce();
        return temp;
    }
    //后置--
    friend Rational operator + (Rational &r1,Rational &r2)
    {
        Rational temp;
        temp.iUp = r1.iUp*r2.iDown +r2.iUp * r1.iDown;
        temp.iDown = r1.iDown*r2.iDown;


        temp.Reduce();
        return temp;
    }
    //两个分数的加法运算
    friend  Rational operator - (Rational &r1,Rational &r2)
    {
        Rational temp((r1.iUp*r2.iDown -r2.iUp*r1.iDown),(r1.iDown*r2.iDown));
//        temp.iUp = r1.iUp*r2.iDown -r2.iUp*r1.iDown;
//        temp.iDown = r1.iDown*r2.iDown;
//        temp.Reduce();

        temp.Reduce();
        return temp;
    }
    //两个数的减法运算
    friend Rational operator * (Rational &r1,Rational &r2)
    {
        Rational temp;
        temp.iUp = r1.iUp*r2.iUp;
        temp.iDown = r1.iDown*r2.iDown;
//        temp.Reduce();

        temp.Reduce();
        return temp;
    }
    //两个数的乘法运算
    friend Rational operator / (Rational &r1,Rational &r2)
    {
        Rational temp;
        temp.iUp = r1.iUp*r2.iDown;
        temp.iDown = r1.iDown*r2.iUp;
//        temp.Reduce();

        temp.Reduce();
        return temp;
    }
//     void  operator | (Rational &r1)
//    {
//        this->iUp = r1.iUp;
//        this->iDown = r1.iDown;
//    }
    friend bool operator > (Rational &r1,Rational &r2)
    {
        if((r1-r2).iUp>0)
            return true;
        else return false;
    }
    friend bool operator < (Rational &r1,Rational &r2)
    {
        if((r1-r2).iUp<0)
            return true;
        else return false;
    }
    friend bool operator >= (Rational &r1,Rational &r2)
    {
        if((r1-r2).iUp>=0)
            return true;
        else return false;
    }
    friend bool operator <= (Rational &r1,Rational &r2)
    {
        if((r1-r2).iUp<=0)
            return true;
        else return false;
    }
//    friend istream & operator >> (istream &in, Rational &p)
//    {
////           in >> p.iUp >> p.iDown;
//        in >> p.iUp >>p.iDown;
//        return in ;
//    }
    friend istream & operator >> (istream &in,Rational & r1)
    {
        in >> r1.iUp >> r1.iDown;
        return in;
    }
    friend ostream & operator << (ostream&out,Rational & r1)
    {
        if(r1.iUp == 0 )
            out << r1.iUp<<endl;
        else if(r1.iUp%r1.iDown==0)
            out << r1.iUp/r1.iDown << endl;
        else out << r1.iUp <<"/"<< r1.iDown<<endl;
        return out;
    }

};



void Run();
int main(int argc, const char * argv[]) {
    // insert code here...

//    Rational r1,r2;
//    cin >> r1;
////    r2 = (++r1);
//    cout << (r1).GetUp() << " " <<(r1).GetDowm()<<endl;
//    r2 = (r2 - r1);
//    cout << (r2-r1).GetUp() << " " << (r2-r1).GetDowm()<<endl;
//    int  l=3,r = 6;
//    Swap(&l, &r);
//    cout << CMM(12,13);
    //cout << "Hello, World!\n";
    Run();
    return 0;
}
//int CMM(int l ,int r)
//{
//    int temp = 1;
//    if (r > l)
//    {
//        Swap(&l, &r);
//    }
//
//    while ( r != 0)
//    {
//        temp = r;
//        r = l % r;
////        if (a % (a%b) ==0)
//        l = temp;
//        if (r > l)
//        {
//        Swap(&l, &r);
//        }
//    }
//    return temp;
//}
void Swap(int *l ,int *r)
{
    *l = *l ^ *r;
    *r = *l ^ *r;
    *l = *l ^ *r;
}
void Run()
{
    Rational a,b,c;
    cin >> a >> b;
//    Rational c = a+b;
    c = a+ b;
    cout << "a+b: " <<c;
//    Rational d = a-b;
    c = a -b;
    cout << "a-b: " <<c;
//    Rational e = a*b;
    c = a * b;
    cout << "a*b: " <<c;
     c = a/b;
    cout << "a/b: " <<c;
     c = -a;
    cout << "-a: " <<c;
//    Rational h = ++a;
    //    a;
//    cout << a;
//    -a;
    c=++a;
    cout << "++a: " <<c;
//    Rational i = --h;
    c=--a;
    cout << "--a: " <<c;
//    --a;
    c = a++;
    cout << "a++: " <<c;
//    ++a;
//    ++a;
//    ++a;
    c = a--;
    cout << "a--: " <<c;
//    --a;
//    --a;
    if(a<b)
    cout << "a<b" <<": true"<<endl;
    else cout << "a<b" <<": false"<<endl;
    if(a<=b)
        cout << "a<=b" <<": true"<<endl;
    else cout << "a<=b" <<": false"<<endl;
    if(a>b)
        cout << "a>b" <<": true"<<endl;
    else cout << "a>b" <<": false"<<endl;
    if(a>=b)
        cout << "a>=b" <<": true"<<endl;
    else cout << "a>=b" <<": false"<<endl;
}



