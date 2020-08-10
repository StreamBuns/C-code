//
//  main.cpp
//  ch974
//
//  Created by 赵桐 on 2020/5/27.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include <iostream>
using namespace std;
void OutArray(int*,int size);
int main(int argc, const char * argv[]) {
    // insert code here...
    int array_size,divisor;
    int *array;
    cin >> array_size >> divisor;
    array = (int*)malloc(array_size*sizeof(int));
    for(int i=0;i<array_size;i++)
    {
        cin>>array[i];
    }
//    OutArray(array,array_size);
    for(int i=0;i<array_size;i++)
    {
        
        for(int j=i+1;j<array_size;j++)
        {
            
        }
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
void OutArray(int*a,int size){
    for(int i=0;i<size;i++)
    {
        cout<<a[i];
    }
}
