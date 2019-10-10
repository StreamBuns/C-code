//
//  main.cpp
//  C++DS
//
//  Created by 赵桐 on 2019/9/19.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef  int T;
const int defaultSize = 100;

class SeqList
{
private:
    T* data;//指向动态内存分配数组的指针
    int maxSize;//动态内存分配数组的大小
    int last;//标识顺序表中最后一个元素的位置
    void Resize(int newSize)
    {
        maxSize = newSize;
        data = new T [maxSize];
        last = defaultSize - 1;
    }
public:
    SeqList(int sz=defaultSize)
    {
        maxSize = defaultSize;
        data = new T [maxSize];
        if(data == NULL)
            cout << "false"<<endl;
        last = 0;
        for (int i = 0 ; i < maxSize; i++  )
        {
            data[i] = 0;
        }
    }
    //构造函数
    SeqList(const SeqList& L)
    {
        this->maxSize = L.maxSize;
        data = new T[maxSize];
        this->last = L.last;
        for (int i = 0 ; i < maxSize; i++  )
        {
            data[i] = L.data[i];
        }
    }
    //拷贝构造函数
    SeqList& operator=(const SeqList& L)
    {
        this->maxSize = L.maxSize;
        data = new T[maxSize];
        this->last = L.last;
        for (int i = 0 ; i < maxSize; i++  )
        {
            data[i] = L.data[i];
        }
        return *this;
    }
    //赋值运算符函数
    ~SeqList()
    {
        delete data;
        data = NULL;
    }
    //析构函数
    
    virtual int Size() const
    {
        return maxSize;
    }
    //返回顺序表的容量
    virtual int Length() const
    {
        if (last != 0)
        return last+1;
        else return last;
    }
    //返回顺序表中元素的个数
    virtual int Search(T & x) const
    {
        int i;
        for ( i = 0;i<=last;i++)
        {
            if (x == data[i])
            {
                return i;
            }
        }
       return 0;
    }
    //在顺序表中搜索x
    virtual int Locate(int i) const
    {
        if (i<0||i>last)
         return 0;
        else return data[i];

    }
    //检验顺序表中是否存在第i个元素
//    virtual bool GetData(int i, T& x) const
//    {
//        if (i<0||i>last)
//            return 1;
//        else return 0;
//    }
    //获取顺序表中第i个位置的元素
    virtual void SetData(int i, T& x)
    {
        data[i] = x;
    }
    //将顺序表中第i个位置的元素赋值为x
    virtual bool IsEmpty() const
    {
        if (maxSize == last)
            return false;
        else return true;
    }
    //顺序表是否为空
    virtual bool IsFull() const
    {
        if (maxSize != last)
            return false;
        else return true;
    }
    //顺序表是否为满
    virtual bool Insert(int i, const T& x)
    {
        if (i<0||i>last||last+1>maxSize)
           return 0;
        for(int j = last ; j >= i ;j--)
        {
            data[j+1] = data[j];
        }
        data[i] = x;
        last++;
        if(data[i]==x)
            return true;
        return false;
    }
    //在顺序表的第i个元素的位置插入x
    virtual bool Remove(int i)
    {
        if (i<0||i>last)
            return 0;
        for(int j = i ; j <= last ;j++)
        {
            data[j] = data[j+1];
        }
       
        last--;
        
        return 1;
    }
    //删除顺序表第i个位置的元素
//
    virtual void Sort()
    {
        for (int i = 0;i<=last;i++)
        {
            for (int j = i+1;j<=last;j++)
            {
                if(data[i] < data[j])
                {
                    data[i] = data[i] ^ data[j];
                    data[j] = data[i] ^ data[j];
                    data[i] = data[i] ^ data[j];
                }
            }
        }
        
    }
    //对顺序表中元素进行排序
    friend istream& operator>>(istream& in, SeqList & L)
    {
//        int ch;
        int i ;
        if(L.last!=0)
         i = L.last+1;
        else i = L.last;
        while (in >> L.data[i])
        {
            i++;
            if(cin.get() =='\n')break;
        }
          L.last = i-1;
//        for (int  j = 0;j<L.maxSize-L.last;j++)
//        {
//            in >> L.data[i];
//            if(cin.get() =='/n')
//                break;
//            in >> ch;
//            if (ch =='\n')
//                break;
//            else
//            {
//                L.data[i] = ch;
//            i++;
//            }
        
      
//        in >> ch;

//        while(ch != '\n')
//        {
//            L.data[i] = ch;
//            L.last++;
//            in >> ch;
//        }
        return in;
    }
    //输入运算符重载
    friend ostream& operator<<(ostream& out, const SeqList& L)
    {
        for (int i = 0 ; i< L.last;i++)
        {
            out << L.data[i]<<endl;
        }
        out << L.data[L.last]<<endl;
        return out;
    }
    //输出运算符重载
    void Reverse ()
    {
        if(last%2 ==0)
        {
            for (int i =0; i < last /2 ; i++)
            {
                data[i] = data[i] ^ data[last - i];
                data[last - i] = data[i] ^ data[last - i];
                data[i] = data[i] ^ data[last - i];
            }
        }
        else
        {
            for (int i =0; i < (last+1) /2 ; i++)
            {
                data[i] = data[i] ^ data[last - i];
                data[last - i] = data[i] ^ data[last - i];
                data[i] = data[i] ^ data[last - i];
            }
        }
    }
    //逆置顺序表中的元素
};

int main()
{
    SeqList sList;
//    int i =1;
//    cin >> sList;
//    sList.Sort();
//    cout << sList ;
//    sList.Reverse();
//    cout << sList;
////    cout << sList.Length();
////    cout << sList;
////    SeqList sList2(sList);
////    cout << sList2.Length();
////    cout << sList2;
////    cout << endl;
//    sList.Insert(2, 10);
//    cout << sList;
//
//    sList.Remove(2);
    
    cin>>sList;
    int i, val;
    cin>>i>>val;
    sList.Insert(i,val);
    cout<<sList;
    cin>>i;
    sList.Remove(i);
    cout<<sList;
    cin>>val;
    i=sList.Search(val);
    if(i==0)
        cout<<"Not found"<<endl;
    else
        cout<<i<<endl;
    sList.Reverse();
    cout<<sList;
}
