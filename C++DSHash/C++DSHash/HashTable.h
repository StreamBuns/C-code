//
//  HashTable.h
//  C++DSHash
//
//  Created by 赵桐 on 2019/12/5.
//  Copyright © 2019 赵桐. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h
#include <iostream>
using namespace std;
const int DefaultSize = 100;
enum KindOfStatus{Active,Empty,Deleted};//元素分类（空间/空/删）
template<typename E,typename K>
class HashTable{
private:
    int divitor;//散列函数的除数
    int CurrentSize,TableSize;//当前桶数和最大桶数
    E * ht;         //散列表存储数组
    KindOfStatus * info;//状态数组
    int FindPos(const K k1)const;//散列函数：计算初始桶号
    int operator ==(E&e1){return *this==e1;}
    int operator !=(E&e1){return *this!=e1;}
public:
    HashTable(const int d,int sz = DefaultSize);
    ~HashTable(){delete[]ht;delete[]info;}
    HashTable<E,K>&operator = (const HashTable<E,K>&ht2);
    bool Search(const K k1,E&e1)const;
    bool Insert(const E&e1);
    bool Remove(const K k1,E&e1);
    void makeEmpty();
    
};
template<typename E,typename K>HashTable<E,K>::HashTable(int d,int sz){
    divitor = d;
    TableSize = sz; CurrentSize = 0;
    ht = new E[TableSize];
    info  = new KindOfStatus[TableSize];
    for(int i=0;i<TableSize;i++)info[i]=Empty;
}
template<typename E,typename K>
int HashTable<E,K>::FindPos(const K k1)const{
    //搜索一个散列表中关键码与k1匹配的元素，搜索成功，则返g回该元素的位置，
    //否则返回插入点，如果有足够的空间
    //z直接探测
//    int i =k1%divitor;
//    int j=i;
//    do{
//        if(info[j]==Empty||(info[j]==Active&&ht[j]==k1))return j;
//        j = (j+1)%TableSize;
//    }while(j!=i);
//    return j;
    
    //二次探测
    int i = k1%divitor;
    int k=0,odd=0,save,j=i;
    while((info[i] ==Active&&ht[i]!=k1)||info[i]==Deleted){
        if(odd==0){
            k++;save = i;
            i = (i+2*k-1)%TableSize;odd=1;
        }
        else{
            i = (save+2*k-1)%TableSize;odd=0;
            if(i<0)i+=TableSize;
        }
        if(i==j)return i;//防止循环一周仍未找到再继续循环
    }
    return i;
}

template<typename E,typename K>
 bool HashTable<E,K>::Search(const K k1,E&e1)const{
    //使用先行探查发在散列表ht（每个桶容纳一个元素）中搜索k1如果k1在表中
    //则函数返回true，并且饮用参数e1返回找到的元素，如果k1不在表中，则返回false
     int i = FindPos(k1);
     if(info[i]!=Active||ht[i]!=k1)return false;
     e1 = ht[i];
     return true;
}
template<typename E,typename K>
void HashTable<E,K>::makeEmpty(){
    for(int i =0;i<TableSize;i++)info[i]=Empty;
    CurrentSize=0;
}
template<typename E,typename K>
HashTable<E,K>& HashTable<E,K>::operator= (const HashTable<E,K>&ht2){
    //复制一个散列表ht2
    if(this!=&ht2){
        delete []ht;delete[]info;
        TableSize = ht2.TableSize;
        ht = new E[TableSize];
        info = new KindOfStatus[TableSize];
        for(int i=0;i<TableSize;i++)
        {
            ht[i] = ht2.ht[i];
            info[i] = ht2.info[i];
        }
        CurrentSize = ht2.CurrentSize;
    }
    return *this;
}
template<typename E,typename K>
bool HashTable<E,K>::Insert(const E&e1){
    //在ht表中搜索，e。若找到则不在插入，若未找到，但表已满，则不在插入，返回false
    //若找到的位置的标志是Empty或者Deleted，不论表是否已满，x插入，返回true
    K k1 = e1;
    int i =FindPos(k1);
    if(info[i]!=Active){
        ht[i] = e1;info[i]=Active;
        CurrentSize++;
        return true;
    }
    if(info[i]==Active&&ht[i]==e1){
        cout<<"表中已有此元素，不能插入！"<<endl;return false;
    }
    cout <<"表已满，不能插入！"<<endl;
    return false;
}
template<typename E,typename K>
bool HashTable<E,K>::Remove(const K k1, E&e1){
    //在ht表中删除元素key。若表中找不到k1，活虽然找到k1，但是他已经逻辑删除了
    //则返回false，否则在表中删除元素kk1，返回true，并在引用参数e1中得到它
    int i =FindPos(k1);
    if(info[i]==Active&&ht[i]==k1){
        info[i]=Deleted;CurrentSize--;
        return true;
    }
    else return false;
}
#endif /* HashTable_h */
