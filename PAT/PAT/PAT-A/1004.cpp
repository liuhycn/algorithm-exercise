#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 101;
vector<vector<int>> g;
queue<int> Q;
queue<int> dep;
int treedep;
int ans[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (!n) return 0;
    g = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        for (int j = 0; j < b; j++)
        {
            int c;
            scanf("%d", &c);
            g[a].push_back(c);
        }
    }
    Q.push(1);
    dep.push(1);
    while (Q.size())
    {
        int curnode = Q.front();
        Q.pop(); 
        int curdep = dep.front();
        dep.pop();
        treedep = curdep;
        int cnt = g[curnode].size();
        if (cnt == 0) 
        {
            ans[curdep] ++;
            continue;
        }
        for (auto node : g[curnode])
        {
            Q.push(node);
            dep.push(curdep + 1);
        }
    }
    for (int i = 1; i <= treedep; i++)
    {
        if (i == 1) printf("%d", ans[i]);
        else printf(" %d", ans[i]);
    }
    return 0;
}