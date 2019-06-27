//
//  main.cpp
//  opp5Test
//
//  Created by 赵桐 on 2019/6/13.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>

using namespace std;
#define N 5

class Vector
{
    int * arr ;
protected:
  int m_number ;
public:
    Vector (int _n)
    {
        arr =  new int [_n];
        for (int i = 0 ; i< _n;i++)
        {
            arr[i] = 0;
        }
        m_number = _n;
    }
    Vector()
    {
        arr = new int [N];
        for (int i = 0;i < N;i++)
        {
            arr[i] = i + 1;
        }
        m_number = N;
    }
    Vector(const  Vector & lv)
    {
        m_number = lv.m_number;
        arr = new int (m_number);
        for (int i = 0 ; i < m_number ; i++ )
        {
            arr[i] = lv.arr[i];
        }
    };
    int mNumber ()
    {
        return m_number;
    }
    void Printf()
    {
//        cout << mNumber();
        int i = 0;
        for (;i < mNumber()-1 ; i++)
        {
            cout << arr[i] << " " ;
        }
        cout << arr[i] ;
        cout << endl;
    }
    int * GetArr()const {return arr;};
    void SetArr(int _n,int _x)
    {
        if(_n <(m_number))
        {
            arr[_n] = _x;
        }
        else cout << "out of boundary"<<endl;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int _n=0 , _x=0 , n=0;
    cin >> n;
    Vector v1;
    Vector v2(n);
    v1.Printf();
    v2.Printf();
    cin >> _n >> _x;
    
    v1.SetArr(_n, _x);
    Vector v3(v1);
    v1.Printf();
    v3.Printf();
//    std::cout << "Hello, World!\n";
    return 0;
}
