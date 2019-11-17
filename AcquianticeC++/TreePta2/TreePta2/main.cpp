//
//  main.cpp
//  TreePta2
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//


#include <iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct Tree{ struct Tree* Lchild;
    struct Tree* Rchild;
    int data;
}bitree;

Tree *root;
int n;

Tree *build(int *per,int *mid,int leng){ Tree *temp; for(int i=0; i<leng; i++)
{
    if(per[0] == mid[i])
    {
        temp = (Tree*)malloc(sizeof(bitree));
        temp->data = mid[i];
        temp->Lchild = build(per+1,mid,i);
        temp->Rchild = build(per+i+1,mid+i+1,leng-i-1);
        return temp;
    }
}
    return NULL;
}

void levelprint(Tree*tree)
{
    int ans=0;
    queue<Tree*>Q;
    
    
    while(!Q.empty())
        Q.pop();
    
    Q.push(tree);
    Tree *temp;
    
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        
        if(ans < n-1)
        {
            ans++;printf("%d ",temp->data);
        }
        
        else if(ans == n-1)
            printf("%d\n",temp->data);
        
        if(temp->Rchild != NULL)
            Q.push(temp->Rchild);
        if(temp->Lchild != NULL)
            Q.push(temp->Lchild);
    }
    
}

int main()
{
    int per[101010];
    int mid[101010];
    
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&mid[i]);
    for(int i=0; i<n; i++)
        scanf("%d",&per[i]);
    
    root = build(per,mid,n);
    levelprint(root);
}



