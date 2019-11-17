//
//  main.cpp
//  LQBTest4
//
//  Created by 赵桐 on 2019/8/16.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
using namespace  std;

void Run();

int main(int argc, const char * argv[]) {
    // insert code here...
    Run();
    //    std::cout << "Hello, World!\n";
    return 0;
}
void Run()
{
    int number,remainder,tempNumber1 = 1,tempNumber2 = 1,tempNumber3 = 0;
    
    cin >> number;
    if(number ==1)
        cout <<1;
    else if(number ==2)
        cout <<1;
    else if (number==3)
        cout <<2;
    else { for (int i=0;i<number-2;i++)
    {
        
        
        tempNumber3 = tempNumber1 + tempNumber2;
        tempNumber3 = tempNumber3%10007;
//        if(tempNumber3 != 0)
        tempNumber1 = tempNumber2;
        tempNumber1 = tempNumber1%10007;

            tempNumber2 = tempNumber3;
            tempNumber2 = tempNumber2%10007;
    }
//        else{
//            tempNumber1 = tempNumber2 = 1;
//        }
        
        cout << tempNumber3;}
}
