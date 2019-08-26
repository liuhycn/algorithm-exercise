#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 501;
const int M = 500001;

vector<vector<int>> ans;
vector<int> cur;
int h[N], e[M], ne[M], w[M], t[M], idx;
int n, m, src, dst;

void add(int a, int b, int c, int d)
{
    e[idx] = b;
    w[idx] = c;
    t[idx] = d;
    ne[idx] = h[a];
    h[a] = idx ++;
}
int dist[N];
int distt[N];
int visit[N];

void dfs(int node, int x, int y)
{
    if (visit[node] == 1 || x < 0 || y < 0) return;
    if (node == dst && x == 0 && y == 0)
    {
        cur.push_back(node);
        visit[node] = 1;
        ans.push_back(cur);
        cur.pop_back();
        visit[node] = 0;
    }
    visit[node] = 1;
    cur.push_back(node);
    
    for (int i = h[node]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j, x - w[i], y - t[i]);
        
    }
    visit[node] = 0;
    cur.pop_back();
    
}


void dj()
{
    memset(dist, 0x3f3f3f3f, sizeof dist);
    dist[src] = 0;
    distt[src] = 0;
    for (int k = 0; k < n; k++)
    {
        int curnode = -1, curdist;
        for (int i = 0; i < n; i++)
        {
            if ((curnode == -1 || dist[i] < curdist) && visit[i] == 0)
            {
                curnode = i;
                curdist = dist[i];
            }
        }
        dist[curnode] = curdist;
        visit[curnode] = 1;
        
        for (int i = h[curnode]; ~i; i = ne[i])
        {
            int j = e[i];
            if (visit[j] == 0 && dist[j] > dist[curnode] + w[i])
            {
                dist[j] = dist[curnode] + w[i];
                distt[j] = distt[curnode] + t[i];
            }
            else if (visit[j] == 0 && dist[j] == dist[curnode] + w[i] && distt[j] > distt[curnode] + t[i])
            {
                distt[j] = distt[curnode] + t[i];
            }
        }
    }
    memset(visit, 0, sizeof visit);
    dfs(src, dist[dst], distt[dst]);
}




int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d%d%d", &n, &m, &src, &dst);
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a == b) continue;
        add(a, b, c, d);
        add(b ,a, c, d);
    }
    dj();
    cur = ans[0];
    for (int i = 0; i < cur.size(); i++)
    {
        printf("%d ", cur[i]);
    }
    printf("%d %d", dist[dst], distt[dst]);
    
    return 0;
}
