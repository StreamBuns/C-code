//
//  main.cpp
//  PtaDS2
//
//  Created by 赵桐 on 2019/9/26.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
using namespace std;
//int * CreatIntArr(int n);
class SeqList
{
    int * data;
    int MaxSize;
    int last;
    void ReSize(int NewSize)
    {
        delete data;
        data = new int[NewSize];
        MaxSize = NewSize;
        last = 0;
    }
public:
    SeqList(int number)
    {
        data = new int[number];
        MaxSize = number;
        last = 0;
    }
    friend istream & operator >>(istream & in , SeqList & l)
    {
        int i = l.last;
     while(in >> l.data[i]&&i<l.MaxSize - 1)
     {
         i++;
     }
        
        
        
        return  in;
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
//    int NumberN,NumberM;
//    cin >> NumberN >> NumberM;
//    int * IntArrN = new int[NumberN];
//    int * IntArrM = new int[NumberM];
//    for(int i = 0 ; i < NumberN ; i++)
//    {
//        cin >> IntArrN[i];
//    }
//    for(int i = 0 ; i < NumberM ; i++)
//    {
//        cin >> IntArrM[i];
//    }
//    for(int i = 0 ; i < NumberN ; i++)
//    {
//        for(int j = 0 ; j < NumberM ; j++)
//        {
//            if(IntArrN[i] == IntArrM[j])
//            {
//                cout << IntArrN[i];
//            }
//        }
    }
    
    
//    std::cout << "Hello, World!\n"；
    return 0;
}
//int * CreatIntArr(int n)
//{
//    int * arr = new int[n];
//    return arr;
//
//}
