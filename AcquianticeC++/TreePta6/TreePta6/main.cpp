//
//  main.cpp
//  TreePta6
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>

#include <stack>
using namespace std;

stack<char> Stack_LC;

struct BinaryTree_Node
{
    char value;
    
    BinaryTree_Node* lChild;
    BinaryTree_Node* rChild;
    
    BinaryTree_Node() : lChild(NULL), rChild(NULL)
    {
    }
};

typedef BinaryTree_Node* BT_Node;

BT_Node Create_BT()
{
    BT_Node root = new BinaryTree_Node();
    char v;
    cin >> v;
     
    if (v != '#')
    {
        root->value = v;
        root->lChild = Create_BT();
        root->rChild = Create_BT();
    }
    
    else
        root = NULL;
    
    return root;
}

void In_traverse(BT_Node root)
{
    if (root == NULL)
        return;
    
    In_traverse(root->lChild);
    cout << root->value;
    Stack_LC.push(root->value);
    
    In_traverse(root->rChild);
}

int main()
{
    BT_Node Tree = Create_BT();
    In_traverse(Tree);
    cout << endl;
    
    while(!Stack_LC.empty())
    {
        cout << Stack_LC.top();
        Stack_LC.pop();
    }
}

