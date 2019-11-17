//
//  main.cpp
//  LQBTest3
//
//  Created by 赵桐 on 2019/8/16.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include <iomanip>
//#include <iomanip>
using namespace std;

#define PI 3.14159265358979323
void Run();

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Run();
//    std::cout << "Hello, World!\n";
    return 0;
}
void Run()
{
    int r;
    cin >> r;
   long double qure = r*r*PI;
   unsigned long long _qure = (qure+0.00000005)*10000000;
    qure = (long double)_qure/10000000;
    cout << setiosflags(ios::fixed)<<setprecision(7)<<qure;
}
