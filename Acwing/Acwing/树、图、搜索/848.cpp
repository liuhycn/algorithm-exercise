//
//  848.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/10.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

const int N = 100001;
const int M = 100001;

int e[M], ne[M], h[N];
int idx;
int in[N];
int n, m;
vector<int> ans;
int sum;
int q[N], hh, tt;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int main()
{
    pp();
    hh = 0;
    tt = -1;
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        in[b] ++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q[++tt] = i;
        }
    }
    while (hh <= tt)
    {
        int cur = q[hh];
        hh ++;
        ans.push_back(cur);
        for (int i = h[cur]; i != -1; i = ne[i])
        {
            in[e[i]] --;
            if (in[e[i]] == 0)
                q[++tt] = e[i];
        }
    }
    if (ans.size() == n)
    {
        for (auto item : ans)
            printf("%d ", item);
    }
    else
        printf("-1");
    return 0;
}
