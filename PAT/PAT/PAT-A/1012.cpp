//
//  1012.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/18.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct stu
{
    string id;
    int c, m, e ,a;
};

bool ccmp(stu a, stu b)
{
    return a.c > b.c;
}

bool mcmp(stu a, stu b)
{
    return a.m > b.m;
}

bool ecmp(stu a, stu b)
{
    return a.e > b.e;
}

bool acmp(stu a, stu b)
{
    return a.a > b.a;
}

const int N = 2001;
stu stus[N];
int rankk[N];
stu crank[N], mrank[N], erank[N], arank[N];
int n, size;

void helper()
{
    for (int i = 0; i < n; i ++)
    {
        crank[i] = stus[i];
        mrank[i] = stus[i];
        erank[i] = stus[i];
        arank[i] = stus[i];
    }
    sort(crank, crank + n, ccmp);
    sort(mrank, mrank + n, mcmp);
    sort(erank, erank + n, ecmp);
    sort(arank, arank + n, acmp);
}

int getcrank(string id)
{
    memset(rankk, 0, sizeof rankk);
    rankk[0] = 0;
    if (crank[0].id == id) return rankk[0];
    for (int i = 1; i < n; i++)
    {
        if (crank[i].c == crank[i - 1].c)
        {
            rankk[i] = rankk[i - 1];
        }
        else
        {
            rankk[i] = i;
        }
        if (crank[i].id == id)
            return rankk[i];
    }
    return -1;
}
int getmrank(string id)
{
    memset(rankk, 0, sizeof rankk);
    rankk[0] = 0;
    if (mrank[0].id == id) return rankk[0];
    for (int i = 1; i < n; i++)
    {
        if (mrank[i].m == mrank[i - 1].m)
        {
            rankk[i] = rankk[i - 1];
        }
        else
        {
            rankk[i] = i;
        }
        if (mrank[i].id == id)
            return rankk[i];
    }
    return -1;
}
int geterank(string id)
{
    memset(rankk, 0, sizeof rankk);
    rankk[0] = 0;
    if (erank[0].id == id) return rankk[0];
    for (int i = 1; i < n; i++)
    {
        if (erank[i].e == erank[i - 1].e)
        {
            rankk[i] = rankk[i - 1];
        }
        else
        {
            rankk[i] = i;
        }
        if (erank[i].id == id)
            return rankk[i];
    }
    return -1;
}
int getarank(string id)
{
    memset(rankk, 0, sizeof rankk);
    rankk[0] = 0;
    if (arank[0].id == id) return rankk[0];
    for (int i = 1; i < n; i++)
    {
        if (arank[i].a == arank[i - 1].a)
        {
            rankk[i] = rankk[i - 1];
        }
        else
        {
            rankk[i] = i;
        }
        if (arank[i].id == id)
            return rankk[i];
    }
    return -1;
}


int main()
{
    cin >> n >> size;
    for (int i = 0; i < n; i++)
    {
        string id;
        int c, m, e, a;
        cin >> id >> c >> m >> e;
        a = (c + m + e) / 3;
        stus[i] = {id, c, m, e, a};
    }
    helper();
    for (int i = 0; i < size; i++)
    {
        string id;
        cin >> id;
        char cat;
        int res;
        int c, m, e ,a;
        a = getarank(id);
        if (a == -1)
        {
            if (i == size - 1)
                printf("N/A");
            else
                printf("N/A\n");
            continue;
        }
        res = a;
        cat = 'A';
        c = getcrank(id);
        if (c < res)
        {
            res = c;
            cat = 'C';
        }
        m = getmrank(id);
        if (m < res)
        {
            cat = 'M';
            res = m;
        }
        e = geterank(id);
        if (e < res)
        {
            res = e;
            cat = 'E';
        }
        if (i == size - 1)
            printf("%d %c", res + 1, cat);
        else
            printf("%d %c\n", res + 1, cat);
    }
    return 0;
}
