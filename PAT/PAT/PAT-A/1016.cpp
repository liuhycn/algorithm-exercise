//
//  1016.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/27.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int cost[25];

struct record
{
    string name;
    int month, day, h, m;
    int time;
    string tag;
    bool operator < (const record &b)const
    {
        if (name != b.name) return name < b.name;
        if (month != b.month) return month < b.month;
        if (day != b.day) return day < b.day;
        if (h != b.h) return h < b.h;
        if (m != b.m) return m < b.m;
        return false;
    }
};

// 计算费用从00:00:00到dd:hh:mm计算可以避免跨天的问题，比如01:12:00到02:02:00

int mm;
vector<record> records;

double helper(record x)
{
    double res = 0;
    res += cost[24] * 60 * x.day;
    for (int i = 0; i < x.h; i++)
    {
        res += cost[i] * 60;
    }
    res += cost[x.h] * x.m;
    return res / 100;
}


int main()
{
    cout << endl;
    for (int i = 0; i < 24; i++)
    {
        scanf("%d", &cost[i]);
        cost[24] += cost[i];
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        string name, tag;
        int month, day, h, m;
        cin >> name;
        scanf("%d:%d:%d:%d", &month, &day, &h, &m);
        cin >> tag;
        mm = month;
        int tmp = day * 24 * 60 + h * 60 + m;
        records.push_back({name, month, day, h, m, tmp, tag});
    }
    sort(records.begin(), records.end());
    map<string, vector<record>> buf;
    for (int i = 0; i < records.size(); i++)
    {
        if (i + 1 < records.size() && (records[i].name == records[i + 1].name && records[i].tag == "on-line" && records[i + 1].tag == "off-line"))
        {
            buf[records[i].name].push_back(records[i]);
            buf[records[i].name].push_back(records[i + 1]);
        }
    }
    for (auto cus : buf)
    {
        printf("%s %02d\n", cus.first.c_str(), mm);
        int loop = cus.second.size();
        double sum = 0;
        for (int i = 0; i < loop; i += 2)
        {
            double tt = helper(cus.second[i + 1]) - helper(cus.second[i]);
            sum += tt;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", cus.second[i].day, cus.second[i].h, cus.second[i].m, cus.second[i + 1].day, cus.second[i + 1].h, cus.second[i + 1].m, cus.second[i + 1].time - cus.second[i].time, tt);
        }
        printf("Total amount: $%.2lf\n", sum);
    }
    return 0;
}
