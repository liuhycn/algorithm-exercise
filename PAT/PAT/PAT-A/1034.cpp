
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> PII;
unordered_map<string, int> stringint;
unordered_map<int, string> intstring;
int cnt;
const int N = 2001;
int g[N][N];
int w[N];
vector<PII> res;
int visit[N];

void dfs(int node, int &laoda, int &renshu, int &sum)
{
    if (visit[node] == 1) return;
    visit[node] = 1;
    if (w[node] > w[laoda])
        laoda = node;
    renshu ++;
    for (int i = 0; i < cnt; i++)
    {
        if (g[node][i] > 0)
        {
            sum += g[node][i];
            g[node][i] = 0;
            g[i][node] = 0;
            dfs(i, laoda, renshu, sum);
        }
    }
}

int main()
{
    cout << endl;
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        string a, b;
        int c;
        cin >> a >> b >> c;
        if (stringint.find(a) == stringint.end())
        {
            stringint[a] = cnt;
            intstring[cnt] = a;
            cnt ++;
        }
        if (stringint.find(b) == stringint.end())
        {
            stringint[b] = cnt;
            intstring[cnt] = b;
            cnt ++;
        }
        w[stringint[a]] += c;
        w[stringint[b]] += c;
        g[stringint[a]][stringint[b]] += c;
        g[stringint[b]][stringint[a]] += c;
    }
    for (int i = 0; i < cnt; i++)
    {
        int renshu = 0;
        int sum = 0;
        int laoda = i;
        dfs(i, laoda, renshu, sum);
        if (renshu > 2 && sum > k)
        {
            res.push_back({intstring[laoda], renshu});
        }
    }
    if (res.size() > 0)
    {
        sort(res.begin(), res.end());
        printf("%d", (int)res.size());
        for (auto pii : res)
        {
            printf("\n");
            printf("%s %d", pii.first.c_str(), pii.second);
        }
    }
    else
    {
        printf("0");
    }
    return 0;
}
