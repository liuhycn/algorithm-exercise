//
//  846.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/10.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

const int N = 100001;

int h[N], e[N*2], ne[N*2];
int n;
int idx;
int visit[N];
int ans = N;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx ++;
}

int dfs(int u)
{
    visit[u] = 1;
    int sum = 1;
    int tmp = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (visit[e[i]] == 1) continue;
        int sub = dfs(e[i]);
        sum += sub;
        tmp = max(tmp, sub);
    }
    tmp = max(tmp, n - sum);
    ans = min(ans, tmp);
    return sum;
}

int main()
{
    pp();
    memset(h, -1, sizeof(h));
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b ,a);
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
