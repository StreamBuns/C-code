//
//  main.cpp
//  LQBTest2
//
//  Created by 赵桐 on 2019/8/11.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
using namespace std;

#define N 20
//class iArr
//{
//   long long int * Arr;
//    int number;
////    char* ArrHex;
//public:
//    iArr(int _number )
//    {
//        number = _number;
//        Arr = new long long int[number];
//        for(int i = 0;i<number ;i++)
//        {
//            Arr[i] = i+1;
//        }
//    }
//    iArr()
//    {
//        Arr = NULL;
//    }
//   long long int sum()
//    {
//        long long int sum = 0;
//        for(int i = 0 ; i < number ; i++)
//        {
//            sum = sum + Arr[i];
//        }
//        return sum;
//    }
//friend istream & operator >>  (istream &in ,iArr  arr1)
//    {
////        int ment = 0;
//        for(int i = 0; i < arr1.number ;i++)
//        {
////            in >> ment;
//            in>>arr1.Arr[i];
//        }
//        return in;
//    }
//    void transform(long long int p);
////    int charng()
//};
//int* creatArr(int number)
//{
//    int * Arr = new int [number];
//    return Arr;
//}
//long long int sum(int number);
int power(int _n);


class sumNext
{
    int number;
    int e;
    long double sum;
public:
    sumNext()
    {
        number = 0;
        e = 0;
        sum = 0;
    }
    sumNext(int _n = 0)
    {
        number = _n;
        e = 0;
        sum = 0.0;
    }
    void juctic()
    {
                long long  ment = sum;
        
                while((sum - ment)!=0)
                {
                    sum  = sum*10;
                    e --;
                    ment = sum;
                }
        //保证sum都是整数切没有0；
//        return ment;
//        if(!(sum < 10))
//        {
//            sum = (sum/10);
//            e++;
//        }
    }
    long double juctic(int n)
    {
        long double _n=n;
        
        while(_n >= 1000)
        {
            _n = (_n/10);
            e++;
        }
        return _n;
    }
    //把number用科学计数法表示。
    long double chang(int n)
    {
        long double equt = n;
        equt = equt / power(e/2);
        return equt;
    }
    //使n(n+1)/2中的1的阶级术于n相同
    void  allSum ()
    {
    sum = juctic(number)*(juctic(number)+chang(1))/2;
 juctic();
        long long i,m=sum;
        
        i = m%10;
        while (i!=0||m!=0)
        {
            cout<<m%10;
            m = m/10;
            i = m%10;
        }
    }
//    long double allSum ()
//    {
//        for (int i = 0 ; i < number ; i++)
//        {
//            juctic();
//            sum = sum + chang(i+1);
//            juctic();
//        }
//        int ment = sum;
//
//        while((sum - ment)!=0)
//        {
//            sum  = sum*10;
//            e --;
//            ment = sum;
//        }
//        return sum;
//    }
    int getE() const{return e;}
};

void zero(int n);


//class Sumnnumber
//{
//    int arr[N];
//    long long number;
//public:
//    Sumnnumber()
//    {
////        arr = NULL;
//        number = 0;
//    }
//    Sumnnumber(long long _number)
//    {
//        number =  _number;
//        for (int i = 0;i<N;i++)
//        {
//            arr[i] = 0;
//        }
//        //把数组初始化为0
//
//    }
//    void sum()
//    {
//        for (int i=0;i<number;i++)
//    }
//
//};
int main(int argc, const char * argv[]) {
    // insert code here...
//    cout << power(0);
//    int a = 1;
//    long double b = a;
//    b = b/1000000;
//    cout << b;
    unsigned long long number,sum;
    cin >> number;
//    sumNext sum1(number);
//    sum1.allSum() ;
//    zero(sum1.getE());
    sum  = number*(number +1 );
    cout <<sum/2;
    
    return 0;
}
int power(int _n)
{
//    int e =1;
//    for(int i=0;i<_n;i++)
//    {
//        e = 10*e;
//    }
//    return e;
    if(_n==0)
    {
        return 1;
    }
    else return 10*power(_n-1);
}
void zero(int n)
{
    for(int i = 0; i<n;i++)
    {
        cout<<0;

    }
}
