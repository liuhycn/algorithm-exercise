//
//  850.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/11.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


// first distance
// second node number
typedef pair<int, int> PII;


priority_queue<PII, vector<PII>, greater<PII>> heap;
const int N = 100001;
const int M = 100001;
int h[N], w[M], idx, e[M], ne[M];
int visit[N];
int n, m;
int ans[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int main()
{
    pp();
    memset(h, -1, sizeof h);
    memset(ans, 0x3f, sizeof ans);
    scanf("%d%d", &n, &m);
    ans[1] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    heap.push({0, 1});
    while (!heap.empty())
    {
        auto node = heap.top();
        heap.pop();
        int cur = node.second;
        int dist = node.first;
        if (visit[cur] == 1) continue;
        visit[cur] = 1;
        ans[cur] = dist;
        for (int i = h[cur]; i != -1; i = ne[i])
        {
            if (visit[e[i]] == 0 && ans[e[i]] > ans[cur] + w[i])
                heap.push({ans[cur] + w[i], e[i]});
        }
    }
    if (ans[n] == 0x3f3f3f3f)
        printf("-1\n");
    else
        printf("%d\n", ans[n]);
    return 0;
}
