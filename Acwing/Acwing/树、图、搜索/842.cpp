//
//  842.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/10.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int n;
vector<int> cur;
int visit[8];

void dfs(int index)
{
    if (index == n)
    {
        for (auto item : cur)
            printf("%d ", item);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 1) continue;
        visit[i] = 1;
        cur.push_back(i);
        dfs(index + 1);
        cur.pop_back();
        visit[i] = 0;
    }
}


int main()
{
    pp();
    scanf("%d", &n);
    dfs(0);
    return 0;
}
