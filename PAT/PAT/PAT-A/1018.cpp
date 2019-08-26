#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 501;
const int M = 200001;

typedef pair<int, int> PII;
vector<PII> wbuf;

int h[N], e[M], ne[M], idx, w[M];
int dist[N], visit[N];
int c[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

vector<vector<int>> ans;
vector<int> cur;
int maxcap;
int n, m, dst;

void dfs(int node, int x)
{
    if (x < 0) return;
    if (node == dst && x == 0)
    {
        cur.push_back(node);
        ans.push_back(cur);
        cur.pop_back();
        return;
    }
    visit[node] = 1;
    cur.push_back(node);
    for (int i = h[node]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!visit[j]) dfs(j, x - w[i]);
    }
    cur.pop_back();
    visit[node] = 0;
}

int main()
{
    cout << endl;
    memset(h, -1, sizeof h);
    memset(dist, 0x3f, sizeof dist);
    scanf("%d%d%d%d", &maxcap, &n, &dst, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == b) continue;
        add(a, b, c);
        add(b, a, c);
    }
    
    dist[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        int curmin = 0x3f3f3f3f, curnode;
        for (int j = 0; j <= n; j++)
        {
            if (visit[j] == 0 && dist[j] < curmin)
            {
                curnode = j;
                curmin = dist[j];
            }
        }
        dist[curnode] = curmin;
        visit[curnode] = 1;
        for (int j = h[curnode]; j != -1; j = ne[j])
        {
            if (visit[e[j]] == 0 && dist[e[j]] > dist[curnode] + w[j])
                dist[e[j]] = dist[curnode] + w[j];
        }
    }
    memset(visit, 0, sizeof visit);
    dfs(0, dist[dst]);
    
    int ansback, ansout = 0x3f3f3f3f;
    vector<int> anspath;
    for (auto path : ans)
    {
        int back = 0, out = 0;
        int stand = maxcap >> 1;
        for (int i = path.size() - 1; i >= 1; i--)
        {
            if (c[path[i]] > stand)
            {
                back += c[path[i]] - stand;
            }
            else if (c[path[i]] < stand)
            {
                out += stand - c[path[i]];
            }
        }
        if (out >= back)
        {
            out -= back;
            back = 0;
        }
        else
        {
            back -= out;
            out = 0;
        }
        if (out < ansout || (out == ansout && back < ansback))
        {
            ansout = out;
            ansback = back;
            anspath = path;
        }
    }
    printf("%d 0", ansout);
    for (int i = 1; i < anspath.size(); i++)
    {
        printf("->%d", anspath[i]);
    }
    printf(" %d", ansback);
    
    return 0;
}
