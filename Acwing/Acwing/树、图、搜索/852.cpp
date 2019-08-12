//
//  852.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/11.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

const int M = 10001;
const int N = 2001;
int h[N], e[M], ne[M], w[M], idx;
int n, m;
int visit[N];
int dist[N], cnt[N];
bool ans;
queue<int> Q;

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
    ans = false;
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b ,c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    
    for (int i = 1; i <= n; i++)
    {
        visit[i] = 1;
        Q.push(i);
    }
    
    while (Q.size())
    {
        int cur = Q.front();
        Q.pop();
        visit[cur] = 0;
        
        for (int i = h[cur]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[cur] + w[i])
            {
                dist[j] = dist[cur] + w[i];
                cnt[j] = cnt[cur] + 1;
                if (cnt[j] == n)
                {
                    ans = true;
                    goto A;
                }
                if (visit[j] == 0)
                {
                    Q.push(j);
                    visit[j] = 1;
                }
            }
        }
    }
    
A:
    if (ans) printf("YES\n");
    else printf("NO\n");
    return 0;
}
