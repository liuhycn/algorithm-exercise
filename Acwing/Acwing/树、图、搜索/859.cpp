//
//  859.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/12.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

const int N = 100001;
const int M = 200001;

int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

struct Edge
{
    int a, b, c;
    bool operator < (const Edge& b) const
    {
        return c < b.c;
    }
}edge[M];

int n, m;
int ans;
int cnt;

int main()
{
    pp();
    
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[i] = {a, b, c};
    }
    for (int i = 1; i <= n; i++)
        p[i] = i;
    sort(edge, edge + m);
    for (int i = 0; i < m; i++)
    {
        auto cur = edge[i];
        int a = cur.a;
        int b = cur.b;
        int c = cur.c;
        if (find(a) == find(b))
        {
            continue;
        }
        else
        {
            cnt ++;
            ans += c;
            p[find(b)] = find(a);
        }
    }
    if (cnt == n - 1)
        printf("%d\n", ans);
    else
        puts("impossible");
    return 0;
}
