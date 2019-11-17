//
//  main.cpp
//  EX2_4
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int Status;
typedef int SElemType;
typedef struct {
   SElemType *base;
   SElemType *top;
   int stacksize;
}SqStack;
Status InitStack(SqStack &S)
{
    S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base) exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}
Status GetTop(SqStack S,SElemType &e)
{
    if(S.top==S.base) return ERROR;
    e=*(S.top-1);
    return OK;
}
Status Push(SqStack &S,SElemType e)
{
    if(S.top-S.base>=S.stacksize){
        S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) exit(OVERFLOW);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}
Status Pop(SqStack &S,char &e)
{
    if(S.top==S.base) return ERROR;
    e=*--S.top;
    return OK;
}
Status Empty(SqStack &S)
{
    if(S.top==S.base) return OK;
    else return ERROR;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while(n--){
        string s; cin>>s;
        char e;
        int len=s.length();
        SqStack S;
        InitStack(S);
        int flag=1;
        int length=0;

        for(int i=0;i<len;i++){

            if(s[i]=='S'){
                Push(S,s[i]);
                length++;
                if(length>m){
                    printf("NO\n");
                    flag=0;
                    break;
                }
            }
            else{
                if(Empty(S)){
                   printf("NO\n");
                   flag=0;
                   break;
                }
                else{
                    Pop(S,e);
                    length--;
                }
            }
        }
        if(flag){
            if(Empty(S)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}

