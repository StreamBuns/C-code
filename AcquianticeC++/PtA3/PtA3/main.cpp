//
//  main.cpp
//  PtA3
//
//  Created by 赵桐 on 2019/10/13.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
using namespace std;
typedef int T;
//#define NULL 0
struct LinkNode
{
    LinkNode * next;
    T data;
    LinkNode(LinkNode* str , T tem)
    {
        next = str;
        data = tem;
    }
    LinkNode()
    {
        next = NULL;
        data = 0;
    }
    LinkNode(T tem)
    {
        next = NULL;
        data = tem;
    }
};
class List
{
private:
    LinkNode * first;
public:
    List()
    {
//        first = new LinkNode;
        first = NULL;
    }
    void InputRear(const T& elem)
        {
            
    //        LinkNode RearLinkNode;
            LinkNode * temp = first;
    //        RearLinkNode.data = elem;
            if(temp != NULL)
            {
            while (temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = new LinkNode(elem);
    //        first = temp;
            }
            else first = new LinkNode(elem);
    //        if(first ==NULL)
    //        {
    //            first = &RearLinkNode;
    //        }
    //        else
    //        {
    ////        RearLinkNode.next = NULL;
    //        while(temp->next != NULL)
    //        {
    //            temp = temp->next;
    ////            temp = RearLinkNode.next;
    ////            RearLinkNode.next = RearLinkNode.next->next;
    //        }
    //        temp->next = &RearLinkNode;
    //        }
    //        RearLinkNode = new LinkNode[1]
        }
//        ListNode  temp;
//        temp.data = tem;
//        temp.next = head;
//
//        head = &temp;
    
    friend istream& operator>>(istream& in, List& L)
    {
        T temp;
        while (in >> temp)
        {
            L.InputRear(temp);
        if(cin.get()=='\n')
        break;
        }
        return in;


        
    }
//    friend ostream & operator <<(ostream&out , List & t)
//    {
//        LinkNode* temp = t.first;
//        while(temp!=NULL)
//        {
//            out << temp->data;
//            temp = temp->next;
//        }
//        return out;
//    }
    friend ostream& operator<<(ostream& out, const List& L)
        {
            LinkNode * Temp = L.first;
    //        Temp = new LinkNode[1];
            while (Temp->next != NULL )
            {
                out << Temp->data<<" ";
                Temp  = Temp->next;
            }
            out << Temp->data;
            
            return  out;
        };
};
int main(int argc, const char * argv[]) {
    // insert code here...
    List l1;
    int number,size;
    cin >> size;
    for(int i = 0 ; i < size ; i++)
    {
        cin >> number;
        l1.InputRear(number);
    }
//    cin >> number;
//    cin >>l1;
    cout << l1;
//    cout << "Hello, World!\n";
    return 0;
}
