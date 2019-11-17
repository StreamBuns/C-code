//
//  main.cpp
//  TreePta9
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
using namespace std;

template<class Elem>
struct BinNode{
    Elem data;
    BinNode<Elem> *left;
    BinNode<Elem> *right;
    BinNode(Elem x){
        data = x;
        left = right = NULL;
    }
};
template<class Elem>
class BinTree{
protected:
    BinNode<Elem> *root;

    BinNode<Elem>* rfindX(Elem x,BinNode<Elem> *r){
        if(!r) return NULL;
        if(r->data == x) return r;
        BinNode<Elem> * found;
        found = rfindX(x,r->left);
        return found ? found : rfindX(x,r->right);
    }

    int rsumofLeave(BinNode<Elem> *r)
    {
        int sum =0;
        if(!r); //空树
        else{
            if(!r->left && !r->right)  //看是否是叶子
            sum +=r->data;
            sum +=rsumofLeave(r->left); // 递归
            sum +=rsumofLeave(r->right);
        }
        return sum;
    }
public:
    BinTree(){
        root = NULL;
    }
    BinTree(Elem r){
        root = new BinNode<Elem>(r);
    }
    ~BinTree(){
        
    }

    BinNode<Elem>* findX(Elem x){
        return rfindX(x,root);
    }
    bool insert(Elem p,int LorR,Elem x){
        BinNode<Elem> *found;
        found = findX(p);
        if(!found) return false;
        if(LorR == 0)
        {
            if(found -> left) return false;
            found->left = new BinNode<Elem>(x);
        }
        else{
            if(found -> right) return false;
            found->right = new BinNode<Elem>(x);
        }
        return true;
    }

    int sumofLeave()
    {
        return rsumofLeave(root);
    }
            
};
int main(int argc, char** argv) {
    int n;
    cin>>n;
    if(n>0){
    int r,LorR,data;
    cin>>r;
    BinTree<int> bt(r);
    for(int i=1;i<n;i++)
    {
        cin >> r >> LorR >> data;
        bt.insert(r,LorR,data);
    }
    cout <<    bt.sumofLeave();
    }
    else cout << 0;
    return 0;
}


