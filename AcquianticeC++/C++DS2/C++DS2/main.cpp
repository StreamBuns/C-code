//
//  main.cpp
//  C++DS2
//
//  Created by 赵桐 on 2019/9/22.
//  Copyright © 2019 赵桐. All rights reserved.
//
// #ifdef __cplus
//#include< iostream>
//#include <cstdlib>
//#include <ctime>
//#endif
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef int T;
struct LinkNode //结点定义
{
  
    T data;//数据域
    LinkNode* next;//链域
    LinkNode(const T& item, LinkNode* ptr=NULL)
    {
        data=item;
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
    List()
    {
//        first = new LinkNode[1];
//        first->data = 0;
//        first->next = NULL;
        first = NULL;
    }
    //构造函数
    //List(const T& x);
    //      List(int n,);
    List(const List& L)
    {
//        first = new LinkNode[1];
//        first = L.first;
//        first->data = L.first->data;
//        first->next = L.first->next;
        first = L.first;
        
    }
    //拷贝构造函数
    List& operator=(const List& L)
    {
//        List temp;
//        temp.first = new LinkNode[1];
//        temp.first->next = first->next;
//        first->data = L.first->data;
//        first = L.first;
        if (L.Length()==0)
            exit(1);
        first = new LinkNode(L.first->data);
        
        LinkNode * TempLeft = first;
        LinkNode * TempRight = L.first->next;
        while(TempRight!=NULL)
        {
            TempLeft->next = new LinkNode(TempRight->data);
            if(TempRight->next!=NULL)
                TempRight = TempRight->next;
            else break;
            TempLeft = TempLeft->next;
                
        }
//        while(TempRight != NULL)
//
//        {
//            TempLeft = new LinkNode[1];
//            TempLeft->data = TempRight->data;
//            TempRight = TempRight->next;
//            if(TempRight != NULL)
//                TempLeft = TempLeft->next;
//            //            TempRight->next = new LinkNode[1];
//            //            TempLeft = TempLeft->next;
//            //            TempRight = TempRight->next;
//            //            TempLeft->data = TempRight->data;
//
//        }
        return *this;
    }
    //赋值运算符函数
    ~List()
    {
//        delete first;
    }
    //析构函数
    
    void InputFront(const T& elem)
    {

        LinkNode* temp = first;
        first = new LinkNode(elem,temp);

    }
    //头插法 OK
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
    //尾插法 OK
    
    void MakeEmpty()
    {
        LinkNode * temp = first;
        LinkNode * deleted = first;
        int length = Length();
        for (int i = 0 ; i < length ; i++)
        {
            temp = temp->next;
            deleted->next = NULL;
            delete deleted;
            deleted = temp;
        }
//        while (temp != NULL)
//        {
//            temp = temp->next;
//            deleted->next = NULL;
//            delete deleted;
//            deleted  = temp;
//        }
//        delete first;
        first = NULL;
        
    }
    //清空链表
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
    //返回链表中结点个数 ok
    
    LinkNode* Search(const T& x)
    {
        LinkNode * temp = first;
        while(temp->data != x && temp != NULL)
        {
            temp = temp->next;
        }
        if (temp == NULL)
            return NULL;
        else return temp;
    }
    //在链表中查找元素x，找到返回它所在结点的地址，否则返回空 ok
    LinkNode* Locate(int i)
    {
        if (i<0)
            return NULL;
        else{
            LinkNode * temp = first;
            for(int j = 0 ; j<i; j++)
            {
                if (temp == NULL)
                    return NULL;
                temp = temp->next;
            }
            return temp;
        }

    }
    //返回链表中第i个结点的地址，i取值不合法则返回空 ok
    
    bool GetData(int i, T& x)const
    {
        if(i<0)
            return false;
        else {
            LinkNode * temp = first;
            for (int j = 0 ; j < i ; j++)
            {
                if (temp == NULL)
                    return false;
                temp = temp->next;
            }
//            int number = temp->data ;
             x = temp->data ;
            return true;
        }
    }
    //获取链表第i个元素，将它赋值给x ok
    void SetData(int i, const T& x)
    {
        if(i<0)
            return exit(1);
        else {
            LinkNode * temp = first;
            for (int j = 0 ; j < i ; j++)
            {
                if (temp == NULL)
                    return exit(1);
                temp = temp->next;
            }
            //            int number = temp->data ;
            temp->data  = x;
//            return true;
        }
        
    }
    //设置链表第i个元素为x ok
    
    bool Insert(int i, const T& x)
    
    {
        if(i<0&&i>=Length())
        return false;
    else {
//        LinkNode temp(x,first);
        LinkNode *TempPrtRight;
        LinkNode *TempPrtLeft = first;
        for (int j = 0 ; j < i-1 ; j++)
        {
            if (TempPrtLeft->next == NULL)
                return false;
            TempPrtLeft = TempPrtLeft->next;
        }
        TempPrtRight = TempPrtLeft->next;
        TempPrtLeft->next = new LinkNode(x,TempPrtRight);
        
//        for (int j = 0 ; j < i-1 ; j++)
//        {
//            if (temp.next == NULL)
//                return false;
//            temp.next = temp.next->next;
//
//        }
//        TempPrt = temp.next ;
//        temp.next = TempPrt->next ;
//        TempPrt->next = &temp;
        
        //            int number = temp->data ;
        //            x = temp->data ;
        return true;
    }
    }
    //在链表的第i个位置上插入元素x ok
    bool Remove(int i, T& x)
    {
        if(i<0)
            return false;
        else {
            LinkNode *temp=first;
            LinkNode *deleted;
            for (int j = 0 ; j < i-1 ; j++)
            {
                if (temp == NULL)
                    return false;
                temp = temp->next;
                
            }
            deleted = temp->next;
            x = deleted->data;
            temp->next = deleted->next;
            delete deleted;
            return true;
        }
    }
    //删除链表第i个位置的元素，并将它的值赋值给x ok
    
    bool IsEmpty() const
    {
        if(first ==NULL)
            return true;
        else return false;
    }
    //返回链表是否为空
    bool IsFull() const
    {
        LinkNode * temp;
        temp = new LinkNode[1];
        if(temp == NULL)
        {
            delete temp;
            return true;
            
        }
        else {
            delete temp;
            return false;
        }
        
    }
    //返回链表是否为满
    void CopyList(const List& L)
    {
        LinkNode* TempRight = L.first;
        LinkNode* TempLeft = first;
//        first = L.first;
//        if(TempRight != NULL)
//            TempLeft = new LinkNode[1];
//        TempLeft->data = TempRight->data;
//        while(TempRight->next != NULL)
        while(TempRight != NULL)

        {
            TempLeft = new LinkNode[1];
            TempLeft->data = TempRight->data;
            TempRight = TempRight->next;
            if(TempRight != NULL)
                TempLeft = TempLeft->next;
//            TempRight->next = new LinkNode[1];
//            TempLeft = TempLeft->next;
//            TempRight = TempRight->next;
//            TempLeft->data = TempRight->data;
            
        }
    }
    //复制链表
    void Sort()
    //思路就是选择排序然后用length（）控制循环次数。
    {
        LinkNode * LeftTemp = first;
        LinkNode * RightTemp = NULL;
        int length = Length();
        for (int i = 0 ; i < length ; i++ )
            //选择排序
        {
            RightTemp = LeftTemp->next;
            for (int j = i ; j <length-1 ; j++)
                // 这里必须是length（）-1，因为右值本来就是左值+1，所以需要在length（）-1，来控制右h值指针的访问路径
            {
                if (RightTemp->data > LeftTemp->data)
                {
                    LeftTemp->data = LeftTemp->data ^ RightTemp->data;
                    RightTemp->data = LeftTemp->data ^ RightTemp->data;
                    LeftTemp->data = LeftTemp->data ^ RightTemp->data;
                }
                RightTemp = RightTemp->next;
            }
            LeftTemp = LeftTemp->next;
            //左边的值加一，用来
//                    LinkNode * Temp = first;
//            //        Temp = new LinkNode[1];
//                    while (Temp != NULL )
//                    {
//                        cout << Temp->data<<endl;
//                        Temp  = Temp->next;
//                    }
//            cout << endl;
            
        }
    }
    //对链表中结点进行排序
    friend ostream& operator<<(ostream& out, const List& L)
    {
        LinkNode * Temp = L.first;
//        Temp = new LinkNode[1];
        while (Temp != NULL )
        {
            out << Temp->data<<endl;
            Temp  = Temp->next;
        }
        
        return  out;
    };
    //输出流运算符重载 OK
    friend istream& operator>>(istream& in, List& L)
    {
        T temp;
        while (in >> temp)
        {
            L.InputFront(temp);
//            L.InputRear(temp);
        if(cin.get()=='\n')
        break;
        }
        return in;


        
    }
    //输入流运算符重载 OK
};

int main()
{
    List lst;
//    int number = 1;
    cin >> lst;
    
//    lst.Remove(1, number);
////    lst.Sort();
    cout << lst.Length();
//    List lstcp;
//    lstcp = lst;
//    cout << lstcp;
    
//    srand(time(NULL));
//    for(int i=1; i<=2; i++)
//        lst.Insert(i,rand()%50);
//    lst.Sort();
//    cout<<lst;
//    int val;
//    lst.Remove(2,val);
//    cout<<lst;
//    List lst1=lst;
////    lst.MakeEmpty();
//    lst=lst1;
//    cout<<lst;
}
