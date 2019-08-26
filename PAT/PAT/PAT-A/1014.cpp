//
//  1014.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/20.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 1001;

struct times
{
    int h, m;
    void add(int x)
    {
        m += x;
        if (m >= 60)
        {
            h += m / 60;
            m = m % 60;
        }
    }
    void display()
    {
        printf("%02d:%02d\n", h, m);
    }
    bool isovertime()
    {
        if (h >= 17)
            return true;
        else return false;
    }
    bool operator == (const times &b)const
    {
        return h == b.h && m == b.m;
    }
    bool isnull()
    {
        return h == -1 && m == -1;
    }
};

struct customer
{
    times begin, end;
    int delay;
    int gate;
    int id;
};

times res[N];
vector<vector<customer>> pipe;
vector<customer> waitt;

int main()
{
    int n ,m, k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < k; i++)
    {
        customer tmp;
        int a;
        scanf("%d", &a);
        tmp.delay = a;
        tmp.begin = {-1, -1};
        tmp.end = {-1, -1};
        tmp.id = i;
        waitt.push_back(tmp);
        res[i] = {-1, -1};
    }
    pipe = vector<vector<customer>>(n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (waitt.size())
            {
                customer tmp = waitt[0];
                tmp.gate = j;
                pipe[j].push_back(tmp);
                waitt.erase(waitt.begin());
            }
        }
    }
    times cur;
    cur.h = 8;
    cur.m = 0;
    int cnt = 0;
    while (!cur.isovertime())
    {
        for (int i = 0; i < n; i++)
        {
            if (pipe[i].size())
            {
                if (pipe[i][0].begin.isnull())
                {
                    pipe[i][0].begin = cur;
                    pipe[i][0].end = pipe[i][0].begin;
                    pipe[i][0].end.add(pipe[i][0].delay);
                    res[pipe[i][0].id] = pipe[i][0].end;
                    cnt ++;
                }
                if (pipe[i][0].end == cur)
                {
                    pipe[i].erase(pipe[i].begin());
                    if (pipe[i].size() < m && waitt.size())
                    {
                        pipe[i].push_back(waitt[0]);
                        waitt.erase(waitt.begin());
                    }
                    if (pipe[i].size())
                    {
                        pipe[i][0].begin = cur;
                        pipe[i][0].end = pipe[i][0].begin;
                        pipe[i][0].end.add(pipe[i][0].delay);
                        res[pipe[i][0].id] = pipe[i][0].end;
                        cnt ++;
                    }
                }
            }
        }
        if (cnt == k) break;
        cur.add(1);
    }
    for (int i = 0; i < q; i++)
    {
        int a;
        scanf("%d", &a);
        if (res[a - 1].isnull()) printf("Sorry\n");
        else res[a - 1].display();
    }
    return 0;
}
