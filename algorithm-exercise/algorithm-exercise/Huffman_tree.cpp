//
//  main.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/10.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//
//  WPL有一个简便运算，就是所有非叶子节点的权重和
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    // insert code here...
    int n;
    while(scanf("%d",&n) != EOF)
    {
        priority_queue<int,vector<int>,greater<int>> heap;          //必须使用小顶堆
        int temp;
        for (int i = 0; i<n; i++)
        {
            scanf("%d",&temp);
            heap.push(temp);
        }
        int ans = 0;
        while(heap.size() > 1)
        {
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();
            heap.push(a+b);
            ans = ans + a + b;
        }
        printf("%d\n",ans);
    }
    return 0;
}
