#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 100001;
const int M = 100001;

int h[N], e[M], ne[M], idx;
int need[N], tag[N], dist[N];
queue<int> nodes;
queue<int> deep;
vector<int> leaves;

double qmi(double a, int b)
{
    if (b == 0) return 1.0;
    if (b == 1) return a;
    double tmp = qmi(a, b >> 1);
    if (b & 1 == 1) return tmp * tmp * a;
    else return tmp * tmp;
}


void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}


int main()
{
    memset(h, -1, sizeof h);
    int n;
    double origin, rate;
    scanf("%d%lf%lf", &n, &origin, &rate);
    rate = rate / 100;
    for (int i = 0; i < n; i++)
    {
        int cnt;
        scanf("%d", &cnt);
        if (cnt == 0)
        {
            int a;
            scanf("%d", &a);
            need[i] = a;
            tag[i] = 1;
            leaves.push_back(i);
        }
        for (int j = 0; j < cnt; j++)
        {
            int a;
            scanf("%d", &a);
            add(i, a);
        }
    }
    if (tag[0] == 1)
    {
        printf("%.1lf", origin * need[0]);
        return 0;
    }
    nodes.push(0);
    deep.push(0);
    int total = 0;
    dist[0] = 0;
    while (nodes.size())
    {
        int curnode = nodes.front();
        nodes.pop();
        int curdeep = deep.front();
        deep.pop();
        for (int i = h[curnode]; i != -1; i = ne[i])
        {
            int j = e[i];
            nodes.push(j);
            deep.push(curdeep + 1);
            dist[j] = curdeep + 1;
            if (tag[curnode] == 1) total ++;
            if (total == leaves.size()) break;
        }
    }
    double res = 0.0;
    for (int i = 0; i < leaves.size(); i++)
    {
        double tmp = origin * need[leaves[i]];
        tmp = tmp * qmi(1 + rate, dist[leaves[i]]);
        res += tmp;
    }
    printf("%.1lf", res);
    return 0;
}
