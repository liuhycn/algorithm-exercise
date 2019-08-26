//
//  1026.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/26.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct person
{
    int arrive, begin, vip, w;
    int h, m, s;
    bool operator < (const person &b)const
    {
        return arrive < b.arrive;
    }
};

struct table
{
    int vip, cnt, free;
    bool operator < (const table &b)const
    {
        return free < b.free;
    }
};


int n;
const int K = 101;
vector<person> customers;
vector<person> res;
table tables[K];

int getnextvip()
{
    int ans = -1;
    for (int i = 0; i <= customers.size(); i++)
    {
        if (customers[i].vip == 1)
        {
            ans = i;
            break;
        }
    }
    return ans;
}



int main()
{
    cout << endl;
    scanf("%d", &n);
    int close = 21 * 3600;
    for (int i = 1; i <= n; i++)
    {
        int h, m ,s, w, vip;
        scanf("%d:%d:%d%d%d", &h, &m, &s, &w, &vip);
        if (w > 120) w = 120;
        person tmp;
        tmp.arrive = h * 3600 + m * 60 + s;
        tmp.vip = vip;
        tmp.w = w;
        tmp.h = h;
        tmp.m = m;
        tmp.s = s;
        customers.push_back(tmp);
    }
    sort(customers.begin(), customers.end());
    int k, m;
    scanf("%d%d", &k, &m);
    for (int i = 0; i < m; i++)
    {
        int v;
        scanf("%d", &v);
        tables[v].vip = 1;
    }
    int flag = 0;
    for (int i = 1; i <= k; i++)
    {
        if (tables[i].vip == 1)
        {
            int nextvip = getnextvip();
            if (nextvip == -1)
            {
                if (customers.size() == 0)
                {
                    flag = 1;
                    break;
                }
                person tmp = customers[0];
                customers.erase(customers.begin());
                tmp.begin = tmp.arrive;
                tables[i].cnt ++;
                tables[i].free = tmp.begin + tmp.w * 60;
                res.push_back(tmp);
            }
            else
            {
                person tmp = customers[nextvip];
                customers.erase(customers.begin() + nextvip);
                tmp.begin = tmp.arrive;
                tables[i].cnt ++;
                tables[i].free = tmp.begin + tmp.w * 60;
                res.push_back(tmp);
            }
        }
        else
        {
            if (customers.size() == 0)
            {
                flag = 1;
                break;
            }
            person tmp = customers[0];
            customers.erase(customers.begin());
            tmp.begin = tmp.arrive;
            tables[i].cnt ++;
            tables[i].free = tmp.begin + tmp.w * 60;
            res.push_back(tmp);
        }
    }
    if (flag == 1)
    {
        
    }
    else
    {
        while (customers.size())
        {
            sort(tables + 1, tables + k + 1);
            if (tables[1].vip == 1)
            {
                int nextvip = getnextvip();
                if (nextvip == -1)
                {
                    person tmp = customers[0];
                    customers.erase(customers.begin());
                    tmp.begin = max(tmp.arrive, tables[1].free);
                    tables[1].cnt ++;
                    tables[1].free = tmp.begin + tmp.w * 60;
                    res.push_back(tmp);
                }
                else
                {
                    person tmp = customers[nextvip];
                    customers.erase(customers.begin() + nextvip);
                    tmp.begin = max(tmp.arrive, tables[1].free);
                    tables[1].cnt ++;
                    tables[1].free = tmp.begin + tmp.w * 60;
                    res.push_back(tmp);
                }
            }
            else
            {
                person tmp = customers[0];
                customers.erase(customers.begin());
                tmp.begin = max(tmp.arrive, tables[1].free);
                tables[1].cnt ++;
                tables[1].free = tmp.begin + tmp.w * 60;
                res.push_back(tmp);
            }
        }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", res[i].begin - res[i].arrive);
    }
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", tables[i].cnt);
    }
    return 0;
}
