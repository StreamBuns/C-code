//
//  main.cpp
//  TreePta12
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include<stdio.h>
#include<stdlib.h>

#define MAX 1001
#define MIN 10001

//这是堆
int heap[MAX];
int size;

/*
    这里的堆是最小堆即
            1
          /      \
         2     3
*/

//初始化堆
void createheap()
{
    size = 0;
    //设置岗哨,方便后面的插入
    heap[0] = MIN;
}

void insert(int x)
{
    int i;
    for (i = ++size; heap[i/2] > x; i /= 2)
    {
        heap[i] = heap[i / 2];
    }
    heap[i] = x;
}


int main()
{
    int n, m;
    scanf("%d%d",&n,&m);

    //初始化堆
    createheap();

    //插入到队中
    int data;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&data);
        insert(data);
    }

    //输入要打印的节点
    int site;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d",&site);
        printf("%d",heap[site]);
        while (site > 1)
        {
            site /= 2;
            printf(" %d",heap[site]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}




