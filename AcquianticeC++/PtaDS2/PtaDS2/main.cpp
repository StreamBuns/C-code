//
//  main.cpp
//  PtaDS2
//
//  Created by 赵桐 on 2019/9/26.
//  Copyright ? 2019 赵桐. All rights reserved.
//

#include <iostream>
using namespace std;
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
    int getMaxSize(){return MaxSize;}
    int getLast(){return last;}
    int* getData(){return data;}
    SeqList(int number)
    {
        data = new int[number];
        MaxSize = number;
        last = 0;
    }
 
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
};
void isEqual(SeqList  &l1, SeqList  &l2)
{
    int temp = ( l1.getMaxSize() > l2.getMaxSize() )? l2.getMaxSize() : l1.getMaxSize();
    int arr[temp];
    temp = 0;
    for(int i = 0 ; i < l1.getMaxSize() ; i++)
    {
        for(int j = 0 ; j < l2.getMaxSize() ; j++)
        {
            if(l1.getData()[i] == l2.getData()[j])
                arr[temp++] = l1.getData()[i];
        }
    }
    
    
    for(int i = 0 ; i < temp-1 ; i ++)
    {

        cout << arr[i] << " ";
    }
    cout <<arr[temp-1];
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int MaxSize1,MaxSize2;
    cin >> MaxSize1 >> MaxSize2;
    if(MaxSize1==0||MaxSize2==0)
    {return 0;}
    else{
        SeqList l1(MaxSize1),l2(MaxSize2);
        cin >> l1 >> l2;
        isEqual(l1,l2);
        return 0;}
}


