//
//  1017.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/21.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct times
{
    int h, m ,s;
    void add(int x)
    {
        m += x;
        h += m / 60;
        m = m % 60;
    }
    bool operator < (const times& b)const
    {
        if (h != b.h) return h < b.h;
        if (m != b.m) return m < b.m;
        if (s != b.s) return s < b.s;
        return false;
    }
    bool operator > (const times& b)const
    {
        if (h != b.h) return h > b.h;
        if (m != b.m) return m > b.m;
        if (s != b.s) return s > b.s;
        return false;
    }
};

struct customer
{
    int v;
    times begin;
    times end;
};

bool cmp1(customer c1, customer c2)
{
    return c1.begin < c2.begin;
}
bool cmp2(customer c1, customer c2)
{
    return c1.end < c2.end;
}

vector<customer> pipe;
vector<customer> waitt;

int main()
{
    int total = 0;
    int n, k, cnt = 0;
    scanf("%d%d", &n, &k);
    times begin = {8, 0, 0};
    times end = {17, 0, 0};
    for (int i = 0; i < n; i++)
    {
        int h, m, s, v;
        scanf("%d:%d:%d %d", &h, &m, &s, &v);
        if (v > 60) v = 60;
        times tmp = {h, m, s};
        if (tmp > end) continue;
        customer cc;
        cc.begin = tmp;
        cc.v = v;
        waitt.push_back(cc);
        cnt ++;
    }
    sort(waitt.begin(), waitt.end(), cmp1);
    for (int i = 0; i < cnt; i++)
    {
        if (waitt[i].begin < begin)
        {
            total += (8 * 3600) - (waitt[i].begin.h * 3600 + waitt[i].begin.m * 60 + waitt[i].begin.s);
            waitt[i].begin = begin;
        }
    }
    while (waitt.size() && pipe.size() < k)
    {
        customer cur = waitt[0];
        waitt.erase(waitt.begin());
        times tmp = cur.begin;
        tmp.add(cur.v);
        cur.end = tmp;
        pipe.push_back(cur);
    }
    sort(pipe.begin(), pipe.end(), cmp2);
    while (waitt.size())
    {
        //弹出 pipe 第一个元素
        times curtime = pipe[0].end;
        pipe.erase(pipe.begin());
        //取出等待队列第一个
        customer newcus = waitt[0];
        waitt.erase(waitt.begin());
        //计算时间
        if ((curtime.h * 3600 + curtime.m * 60 + curtime.s) - (newcus.begin.h * 3600 + newcus.begin.m * 60 + newcus.begin.s) > 0)
            total += (curtime.h * 3600 + curtime.m * 60 + curtime.s) - (newcus.begin.h * 3600 + newcus.begin.m * 60 + newcus.begin.s);
        else
        {
            curtime = newcus.begin;
        }
        newcus.begin = curtime;
        curtime.add(newcus.v);
        newcus.end = curtime;
        pipe.push_back(newcus);
        sort(pipe.begin(), pipe.end(), cmp2);
    }
    if (cnt == 0)
    printf("0.0");
    else
    {
        float res = (float)total / (float)cnt / 60.0;
        printf("%.1f", res);
    }
    return 0;
}
