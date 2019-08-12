//
//  851.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/11.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int n, m;
const int N = 100001;
const int M = 100001;

int h[N], w[M], e[M], ne[M];
int q[N];
int tt, hh, idx;

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int dist[N];
int visit[N];

int main()
{
    pp();
    memset(h, -1, sizeof h);
    hh = 0;
    tt = -1;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    q[++tt] = 1;
    visit[1] = 1;
    
    while (hh <= tt)
    {
        int cur = q[hh];
        hh ++;
        visit[cur] = 0;
        for (int i = h[cur]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[cur] + w[i])
            {
                dist[j] = dist[cur] + w[i];
                if (visit[j] == 0)
                {
                    q[++tt] = j;
                    visit[j] = 1;
                }
            }
        }
    }
    
    if (dist[n] > 0x3f3f3f3f >> 1) printf("impossible\n");
    else printf("%d\n", dist[n]);
    return 0;
}
