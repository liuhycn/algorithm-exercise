#include <iostream>
#include <cstring>

using namespace std;

const int N = 1001;
const int M = 1000001;
int h[N], e[M], ne[M], idx;
int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
int main()
{
    int n ,m, k;
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == b) continue;
        add(a, b);
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j <= n; j++)
            p[j] = j;
        int a;
        scanf("%d", &a);
        for (int j = 1; j <= n; j++)
        {
            if (j == a) continue;
            for (int node = h[j]; node != -1; node = ne[node])
            {
                if (e[node] == a) continue;
                p[find(j)] = find(e[node]);
            }
        }
        int sum = 0;
        for (int j = 1; j <= n; j ++)
        {
            if (p[j] == j) sum ++;
        }
        printf("%d\n", sum - 2);
    }
    return 0;
}
