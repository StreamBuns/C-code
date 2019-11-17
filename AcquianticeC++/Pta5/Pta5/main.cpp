//
//  main.cpp
//  Pta6
//
//  Created by 赵桐 on 2019/10/20.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;
typedef string T;
struct LinkNode
{
    int order;
    T address;
    T data;
    T nextAddress;
    LinkNode* next;
    LinkNode(const T address, const T data,const T nextAddress,LinkNode* ptr=NULL)
    {
        this->address = address;
        this->data = data;
        this->nextAddress = nextAddress;
        //        data=item;
        next=ptr;
    }
    LinkNode(LinkNode* ptr=NULL)
    {
        
        next=ptr;
    }
};
class List
{
private:
    LinkNode * first;
public:
    List(int number)
    {
        first = new LinkNode;
        LinkNode * temp = first;
        for ( int i =0; i < number-1; i++)
        {
            temp->next = new LinkNode;
            temp = temp->next;
        }
    }
    int Length() const
    {
        LinkNode * NumberTemp = first;
        int number = 0;
        while (NumberTemp != NULL)
        {
            number++;
            if(NumberTemp->next!=NULL)
                NumberTemp = NumberTemp->next;
            else break;
        }
        //        number++;
        return number;
    }
    
    friend ostream& operator<<(ostream& out, const List& L)
    {
        LinkNode * Temp = L.first;
        //        Temp = new LinkNode[1];
        while (Temp != NULL )
        {
            out <<Temp->address<<" "<< Temp->data<<" "<<Temp->nextAddress<<endl;
            Temp  = Temp->next;
        }
        //            int length = L.Length();
        //            for(int i = 0 ; i< length-1 ; i++)
        //            {
        //
        //            printf("%05d %d %05d\n",Temp->address, Temp->data,Temp->nextAddress);
        //                //  out <<Temp->address<<" "<< Temp->data<<" "<<Temp->nextAddress<<endl;
        //            Temp  = Temp->next;
        //
        //            }
        //            printf("%05d %d %d\n",Temp->address, Temp->data,Temp->nextAddress);
        return  out;
    };
    //输出流运算符重载 OK
    
    friend istream& operator>>(istream& in, List& L)
    {
        LinkNode * temp = L.first;
        while(temp !=NULL)
        {
            in >> temp->address >> temp->data >> temp->nextAddress;
            temp  = temp->next;
        }
        return in;
    }
    void Sort(string firPrt,int datum)
    {
        
        LinkNode * LeftTemp = first;
        LinkNode * RightTemp = NULL;
        int length = Length();
        string order = firPrt;
        if(length >2)
        {
            for (int i = 0 ; i < length ; i++ )
            {
                if(LeftTemp->address == order)
                {
                    LeftTemp->order = 1;
                    break;
                }
                LeftTemp = LeftTemp->next;
        }
            //先找到第一个元素并标记为1
            order = LeftTemp->nextAddress;
            //用第一个元素的后一个地址开始找第二个元素
            int m = 2;
            for (int i = 0 ; i < length-1 ; i++ )
            {
                LeftTemp = first;
                for (int j = 0 ; j < length; j++)
                {
                    if(LeftTemp->address == order)
                    {
                        LeftTemp->order = m++;
                        order = LeftTemp->nextAddress;
                        break;
                    }
                    LeftTemp = LeftTemp->next;
                }
            }
            
            
            LeftTemp = first;
            for (int i = 0 ; i < length ; i++ )
            {
                RightTemp = LeftTemp->next;
                for (int j = i ; j < length-1; j++)
                {
//                    if(i<datum)
//                    {
                        if(RightTemp->order > LeftTemp->order)
                        {
                            
                            LeftTemp->data.swap(RightTemp->data);
                            LeftTemp->address.swap(RightTemp->address);
                            RightTemp->order = LeftTemp->order ^ RightTemp->order;
                            LeftTemp->order = LeftTemp->order ^ RightTemp->order;
                            RightTemp->order = LeftTemp->order ^ RightTemp->order;
                        }
                        RightTemp = RightTemp->next;
//                    }
//                    else
//                    {
//                        if(RightTemp->order < LeftTemp->order)
//                        {
//
//                            LeftTemp->data.swap(RightTemp->data);
//                            LeftTemp->address.swap(RightTemp->address);
//                            RightTemp->order = LeftTemp->order ^ RightTemp->order;
//                            LeftTemp->order = LeftTemp->order ^ RightTemp->order;
//                            RightTemp->order = LeftTemp->order ^ RightTemp->order;
//                        }
//                        RightTemp = RightTemp->next;
//                    }
                }
                LeftTemp = LeftTemp->next;
                
            }
            
            for(int i =0 ;i<length-datum;i++)
            {
                LinkNode *temp = first;
                first =  first->next;
                RightTemp = first;
                for(int j=0 ; j<length-(i+1)-1;j++)
                {
                    RightTemp = RightTemp->next;
                }
                temp->next = RightTemp->next;
                RightTemp->next = temp;
                
            }
            
            
            
            
            LeftTemp = first;
            for (int i = 0 ; i < length-1 ; i++ )
            {
                RightTemp = LeftTemp->next;
                LeftTemp->nextAddress = RightTemp->address;
                LeftTemp = LeftTemp->next;
            }
            LeftTemp->nextAddress = "-1";
            
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int number,datum;
    string firstAddres;
    
    
    cin >> firstAddres >> number>>datum;
    List l(number);
    cin >> l;
    l.Sort(firstAddres,datum);
    cout << l;
    //    std::cout << "Hello, World!\n";
    return 0;
}





 
