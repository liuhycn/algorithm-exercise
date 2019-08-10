//
//  847.cpp
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
int n, m;
int q[N];
int hh, tt, dhh, dtt;
int visit[N];
int ans;
int qdist[N];
int flag;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int main()
{
    pp();
    flag = 0;
    memset(h, -1, sizeof(h));
    hh = 0; dhh = 0;
    tt = -1; dtt = -1;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    q[++tt] = 1;
    qdist[++dtt] = 0;
    while (hh <= tt)
    {
        int cur = q[hh];
        hh ++;
        int curdist = qdist[dhh];
        dhh ++;
        if (visit[cur] == 1) continue;
        visit[cur] = 1;
        if (cur == n)
        {
            ans = curdist;
            flag = 1;
            break;
        }
        for (int i = h[cur]; i != -1; i = ne[i])
        {
            q[++tt] = e[i];
            qdist[++dtt] = curdist + 1;
        }
    }
    if (flag)
        printf("%d\n", ans);
    else
        printf("-1\n");
    return 0;
}
