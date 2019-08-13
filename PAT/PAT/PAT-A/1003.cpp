//
//  1003.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/13.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int N = 501;
int g[N][N];
vector<vector<int>> ans;
vector<int> cur;
int dist[N];
int w[N];
int visit[N];
int n, m, src, dst;
int mindist;
int maxw;

int dj()
{
    memset(dist, 0x3f, sizeof dist);
    dist[src] = 0;
    for (int i = 0; i < n; i++)
    {
        int cur, min = 0x3f3f3f3f;
        for (int j = 0; j < n; j++)
        {
            if (visit[j] == 0 && dist[j] < min)
            {
                cur = j;
                min = dist[j];
            }
        }
        visit[cur] = 1;
        
        for (int j = 0; j < n; j++)
        {
            if (visit[j] == 0 && dist[j] > dist[cur] + g[cur][j])
                dist[j] = dist[cur] + g[cur][j];
        }
    }
    return dist[dst];
}

void dfs(int tar)
{
    int curnode = cur[cur.size() - 1];
    if (curnode != dst && tar <= 0)
        return;
    if (curnode == dst && tar == 0)
    {
        ans.push_back(cur);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (g[curnode][i] != 0x3f3f3f3f && i != curnode && visit[i] == 0)
        {
            visit[i] = 1;
            cur.push_back(i);
            dfs(tar - g[curnode][i]);
            cur.pop_back();
            visit[i] = 0;
        }
    }
}


int main()
{
    printf("right\n");
    memset(g, 0x3f, sizeof g);
    scanf("%d%d%d%d", &n, &m, &src, &dst);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    for (int i = 0; i < n; i++)
        g[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
        g[b][a] = g[a][b];
    }
    mindist = dj();
    memset(visit, 0, sizeof visit);
    visit[src] = 1;
    cur.push_back(src);
    dfs(mindist);
    for (auto item : ans)
    {
        int sum = 0;
        for (auto i : item)
            sum += w[i];
        maxw = max(maxw, sum);
    }
    printf("%d %d", ans.size(), maxw);
    return 0;
}
