//
//  main.cpp
//  TreePta10
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
 
deque<int> de;
int map[10005];
int sum, total;
 
int main()
{
    int n;
    sum = total = 0;
    scanf("%d", &n);
//    cin>>n;
    while(n--)
    {
        int t;
    //    cin>>t;
        scanf("%d", &t);
        total += t;
        de.push_back(t);
    }
    sort(de.begin(), de.end());
    while(de.size() > 1)
    {
        int t;
        t = de.front();
        de.pop_front();
        t += de.front();
        sum += t;
        de.pop_front();
//        de.push_front(t);
        bool flag = true;
        for(int i = 0; i < de.size(); ++i)
            if(de[i] >= t)
            {
                de.insert(de.begin()+i, t);
                flag = false;
                break;
            }
        if(flag)
            de.push_back(t);
    }
    printf("%d\n", sum);
    //cout<<sum<<endl;
    return 0;
}


