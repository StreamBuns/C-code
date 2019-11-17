//
//  main.cpp
//  TreePta5
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include<map>
using namespace std;
 
int N, Q, root = 0;
 
struct Node{
    long long val;
    int l = -1;
    int r = -1;
    int fa = -1;
    int lev = 0;
}node[110];
 
map<long long, int> mp, vis;

void BuildBST(int root, int x) {
    if(node[root].val > node[x].val) {
        if(node[root].l == -1) {
            node[root].l = x;
            node[x].fa = root;
            node[x].lev = node[root].lev + 1;
        } else BuildBST(node[root].l, x);
    } else if(node[root].val <= node[x].val) {
        if(node[root].r == -1) {
            node[root].r = x;
            node[x].fa = root;
            node[x].lev = node[root].lev + 1;
        } else BuildBST(node[root].r, x);
    }
}
 
long long getnum(string s) {
    long long ans = 0;
    int len = s.length();
    bool flag = false;
    for(int i = 0; i < len; i ++) {
        if(s[i] == '-') {
            flag = true;
            break;
        }
    }
    for(int i = 0; i < len; i ++) {
        if(s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
        }
    }
 
    if(flag) ans *= (-1);
    return ans;
}
 
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i ++) {
        long long x;
        scanf("%lld", &x);
        node[i].val = x;
        vis[x] = 1;
        mp[x] = i;
    }
 
    for(int i = 1; i < N; i ++)
        BuildBST(root, i);
 
    scanf("%d", &Q);
    getchar();
    while(Q --) {
        long long num1, num2;
        scanf("%lld", &num1);
        string s;
        getline(cin, s);
 
        if(s.find("root") != -1) {
            if(num1 != node[root].val) printf("No\n");
            else printf("Yes\n");
        } else {
            num2 = getnum(s);
            if(vis[num1] == 0 || vis[num2] == 0) {
                printf("No\n");
                continue;
            }
            if(s.find("left") != -1) {
                if(mp[num1] == node[mp[num2]].l) printf("Yes\n");
                else printf("No\n");
            } else if(s.find("right") != -1) {
                if(mp[num1] == node[mp[num2]].r) printf("Yes\n");
                else printf("No\n");
            } else if(s.find("siblings") != -1) {
                if(node[mp[num1]].fa == node[mp[num2]].fa) printf("Yes\n");
                else printf("No\n");
            } else if(s.find("parent") != -1) {
                if(node[mp[num2]].fa == mp[num1]) printf("Yes\n");
                else printf("No\n");
            } else if(s.find("level") != -1) {
                if(node[mp[num1]].lev == node[mp[num2]].lev) printf("Yes\n");
                else printf("No\n");
            }
            //printf("%d\n", num2);
        }
    }
 
    return 0;
}

