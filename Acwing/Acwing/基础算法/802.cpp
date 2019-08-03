//
//  802.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/31.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

typedef pair<int, int> PII;

int a[300001];
int s[300001];

vector<int> all;
vector<PII> add;
vector<PII> query;

int n, m;


int bsearch(int x)
{
    int l = 0;
    int r = all.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (all[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l + 1;
}

int main()
{
    pp();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x, c;
        scanf("%d%d", &x, &c);
        all.push_back(x);
        add.push_back({x, c});
    }
    for (int i = 0; i < m; i++)
    {
        int l , r;
        scanf("%d%d", &l, &r);
        all.push_back(l);
        all.push_back(r);
        query.push_back({l, r});
    }
    
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    
    for (auto item : add)
    {
        int x = bsearch(item.first);
        a[x] += item.second;
    }
    for (int i = 1; i <= all.size(); i++) s[i] = a[i] + s[i - 1];
    for (auto item : query)
    {
        int l = bsearch(item.first);
        int r = bsearch(item.second);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}
