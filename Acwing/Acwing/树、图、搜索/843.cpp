//
//  843.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/10.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int n;
vector<vector<int>> ans;
vector<vector<int>> visit;
vector<int> cur;

bool check(int x, int y)
{
    int i, j;
    i = x;
    j = y;
    while (i - 1 >= 0)
    {
        if (visit[i - 1][j] == 1)
            return false;
        i --;
    }
    i = x;
    j = y;
    while (i - 1 >= 0 && j - 1 >= 0)
    {
        if (visit[i - 1][j - 1] == 1)
            return false;
        i --;
        j --;
    }
    i = x;
    j = y;
    while (i - 1 >= 0 && j + 1 < n)
    {
        if (visit[i - 1][j + 1] == 1)
            return false;
        i --;
        j ++;
    }
    return true;
}

void dfs(int index)
{
    if (index == n)
    {
        ans.push_back(cur);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check(index, i))
        {
            visit[index][i] = 1;
            cur.push_back(i);
            dfs(index + 1);
            visit[index][i] = 0;
            cur.pop_back();
        }
    }
}

int main()
{
    pp();
    scanf("%d", &n);
    visit = vector<vector<int>>(n);
    for (auto &item : visit)
        item = vector<int>(n, 0);
    dfs(0);
    for (auto item : ans)
    {
        int len = item.size();
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == item[i])
                    printf("Q");
                else
                    printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
