#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1020;
const int M = 20001;

int n, m, k, ds;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], visit[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int toint(string str)
{
    int res;
    sscanf(str.c_str(), "%d", &res);
    return res;
}

int getid(string str)
{
    if (str[0] == 'G')
    {
        str.erase(str.begin());
        return toint(str) + n;
    }
    else return toint(str);
}

void dj(int src)
{
    memset(dist, 0x3f, sizeof dist);
    memset(visit, 0, sizeof visit);
    dist[src] = 0;
    for (int i = 1; i <= n + m; i++)
    {
        int curnode = -1;
        int mindist = 0x3f3f3f3f;
        for (int j = 1; j <= n + m; j++)
        {
            if (visit[j] == 0 && dist[j] < mindist)
            {
                curnode = j;
                mindist = dist[j];
            }
        }
        if (curnode == -1) break;
        visit[curnode] = 1;
        for (int j = h[curnode]; ~j; j = ne[j])
        {
            if (visit[e[j]] == 0 && dist[e[j]] > dist[curnode] + w[j])
                dist[e[j]] = dist[curnode] + w[j];
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    for (int i = 0; i < k; i++)
    {
        string src, dst;
        int w;
        cin >> src >> dst >> w;
        add(getid(src), getid(dst), w);
        add(getid(dst), getid(src), w);
    }
    int resnode = -1, resmindist = -1;
    double resavg = 0.0;
    for (int i = n + 1; i <= n + m; i++)
    {
        dj(i);
        int flag = 0, mindist = 0x3f3f3f3f;
        double sum = 0.0;
        for (int j = 1; j <= n; j++)
        {
            if (dist[j] > ds)
            {
                flag = 1;
                break;
            }
            if (dist[j] < mindist) mindist = dist[j];
            sum += dist[j];
        }
        if (flag == 1) continue;
        if (mindist > resmindist)
        {
            resmindist = mindist;
            resnode = i;
            resavg = 1.0 * sum / n;
        }
        if (mindist == resmindist)
        {
            if ((1.0 * sum / n) < resavg)
            {
                resmindist = mindist;
                resnode = i;
                resavg = 1.0 * sum / n;
            }
        }
    }
    if (resnode == -1) printf("No Solution");
    else
    {
        printf("G%d\n", resnode - n);
        printf("%.1lf %.1lf", (double)resmindist, resavg);
    }
    return 0;
}
