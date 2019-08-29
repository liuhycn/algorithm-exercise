#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1001;
vector<int> cur;
vector<vector<int>> res;
int g[N][N];
int w[N];
int isleaf[N];

int n, m, tar;

struct path
{
    int len;
    int nodes[N];
    void init()
    {
        len = 0;
        memset(nodes, 0, sizeof nodes);
    }
};
vector<path> buf;

// cmp必须写<或>,不能写成<=或>=。否则，可能出现段错误！！！
bool cmp(path p1, path p2)
{
    
    int len1 = p1.len;
    int len2 = p2.len;
    int loop = min(len1, len2);
    int k = 0;
    while (k < loop && p1.nodes[k] == p2.nodes[k]) k++;
    if (k == len1 && len1 == len2) return false;
    if (k == len1) return true;
    if (k == len2) return false;
    if (p1.nodes[k] < p2.nodes[k]) return true;
    else return false;
    
    // return false;
}


void dfs(int node, int x)
{
    if (w[node] == x && isleaf[node] == 0)
    {
        cur.push_back(w[node]);
        res.push_back(cur);
        cur.pop_back();
        return;
    }
    if (w[node] == x && isleaf[node] == 1) return;
    if (w[node] > x) return;
    cur.push_back(w[node]);
    for (int i = 0; i < n; i++)
    {
        if (g[node][i] == 1)
        {
            dfs(i, x - w[node]);
        }
    }
    cur.pop_back();
}

int main()
{
    scanf("%d%d%d", &n, &m, &tar);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    for (int i = 0; i < m; i++)
    {
        int src, cnt;
        scanf("%d%d", &src, &cnt);
        isleaf[src] = 1;
        for (int j = 0; j < cnt; j++)
        {
            int dst;
            scanf("%d", &dst);
            g[src][dst] = 1;
        }
    }
    dfs(0, tar);
    for (auto ans : res)
    {
        path tmp;
        tmp.init();
        tmp.len = ans.size();
        for (int i = 0; i < ans.size(); i++)
        {
            tmp.nodes[i] = ans[i];
        }
        buf.push_back(tmp);
    }
    sort(buf.begin(), buf.end(), cmp);
    
    for (int i = buf.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < buf[i].len; j++)
        {
            if (j == 0) printf("%d", buf[i].nodes[j]);
            else printf(" %d", buf[i].nodes[j]);
        }
        printf("\n");
    }
    
    return 0;
}
