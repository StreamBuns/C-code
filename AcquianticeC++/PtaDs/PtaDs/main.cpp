//
//  main.cpp
//  PtaDs
//
//  Created by 赵桐 on 2019/9/26.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
using namespace std;
//void InArr(int n , int * arr);
class SeqList
{
    int * data;
    int MaxSize;
    int last;
    void ReSise(int NewSize)
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
//        if(data == NULL)
//            cout<< "Creat Arr False!"<<endl;
        MaxSize = number;
        last = 0;
    }
//    int getLast(){return last;}
//    int getMaxsize(){return MaxSize;}
    
    friend istream & operator >> (istream & in,SeqList & l)
    {
        int i ;
        if(l.last == 0 )
        {
            i = l.last;
        }
        else i = l.last + 1;
        while ( i < l.MaxSize&&in >> l.data[i] )
        {
            i++;
            l.last++;
            
            if(cin.get() =='\n')
                break;
        }
        return in;
    }
    
    friend ostream & operator << (ostream & out,SeqList & l)
    {
        
        for ( int i = 0; i < l.last-1 ; i++)
        {
            
            out << l.data[i]<<" ";
        }
        out << l.data[l.last-1]<<endl;
        return out;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int number;
    cin >> number ;
    if(number != 0)
    {
    SeqList l(number);
    cin >> l;
    cout << l;
    }
    return 0;
}

