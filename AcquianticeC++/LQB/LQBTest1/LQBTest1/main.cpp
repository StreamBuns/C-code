//
//  main.cpp
//  LQBTest1
//
//  Created by 赵桐 on 2019/8/11.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
using namespace std;
template  <class _T>
_T Sum(_T _vir1,_T _vir2)
{
    return _vir1+_vir2;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int  ivr1,ivr2;
    cin >> ivr1 >> ivr2;
    std::cout << Sum<int>(ivr1, ivr2);
    return 0;
}
