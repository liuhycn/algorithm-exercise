//
//  1056.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/3.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

struct node
{
    int weight;
    int inputno;
    int rank;
    bool operator < (const node &b)const
    {
        return inputno < b.inputno;
    }
};

vector<node> guanzhong;
vector<node> battle;
vector<vector<node>> loser;

int main()
{
    pp();
    int n, g;
    scanf("%d%d", &n, &g);
    for (int i = 0; i < n; i++)
    {
        node tmp;
        scanf("%d", &tmp.weight);
        tmp.inputno = i;
        guanzhong.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        int order;
        scanf("%d", &order);
        battle.push_back(guanzhong[order]);
    }
    guanzhong.clear();
    while (battle.size() != 1)
    {
        vector<node> win;
        vector<node> loose;
        while (!battle.empty())
        {
            vector<node> group;
            if (battle.size() >= g)
            {
                int max = -1;
                int maxindex = 0;
                for (int i = 0; i < g; i++)
                {
                    group.push_back(battle[0]);
                    battle.erase(battle.begin());
                }
                for (int i = 0; i < g; i++)
                {
                    if (group[i].weight > max)
                    {
                        max = group[i].weight;
                        maxindex = i;
                    }
                }
                win.push_back(group[maxindex]);
                for (int i = 0; i < g; i++)
                {
                    if (i != maxindex)
                        loose.push_back(group[i]);
                }
            }
            else
            {
                int max = -1;
                int maxindex = 0;
                while (!battle.empty())
                {
                    group.push_back(battle[0]);
                    battle.erase(battle.begin());
                }
                for (int i = 0; i < group.size(); i++)
                {
                    if (group[i].weight > max)
                    {
                        max = group[i].weight;
                        maxindex = i;
                    }
                }
                win.push_back(group[maxindex]);
                for (int i = 0; i < group.size(); i++)
                {
                    if (i != maxindex)
                        loose.push_back(group[i]);
                }
            }
        }
        loser.push_back(loose);
        battle.clear();
        while (!win.empty())
        {
            battle.push_back(win[0]);
            win.erase(win.begin());
        }
    }
    loser.push_back(battle);
    reverse(loser.begin(), loser.end());
    int rank = 1;
    guanzhong.clear();
    for (auto item : loser)
    {
        int cnt = 0;
        for (int i = 0; i < item.size(); i++)
        {
            item[i].rank = rank;
            guanzhong.push_back(item[i]);
            cnt ++;
        }
        rank += cnt;
    }
    sort(guanzhong.begin(), guanzhong.end());
    int flag = 0;
    for (auto item : guanzhong)
    {
        if (flag == 0)
        {
            flag = 1;
            printf("%d", item.rank);
        }
        else
            printf(" %d", item.rank);
    }
    return 0;
}
