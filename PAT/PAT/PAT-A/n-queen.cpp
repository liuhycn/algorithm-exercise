//
//  n-queen.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/1.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int ans[51];
bool visit[51];

int n;
int cnt;

bool isok(int index)
{
    if(index == 1)
    {
        return true;
    }
    for(int i = 1;i<=index;i++)
    {
        for(int j = i+1;j<=index;j++)
        {
            if(abs(i - j) == abs(ans[i] - ans[j]))
            {
                return false;
            }
        }
    }
    return true;
}

void dfs(int index)
{
    if(index == n + 1)
    {
        for(int i = 1;i<=n;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
        cnt++;
        return;
    }
    for(int i = 1;i<=n;i++)
    {
        if(visit[i] == true)
        {
            continue;
        }
        ans[index] = i;
        visit[i] = true;
        if(!isok(index))
        {
            visit[i] = false;
            continue;
        }
        dfs(index+1);
        visit[i] = false;
    }
}

int main()
{
    pp();
    while(scanf("%d",&n)!=EOF)
    {
        memset(ans, 0, sizeof(ans));
        memset(visit, 0, sizeof(visit));
        cnt = 0;
        dfs(1);
        printf("%d\n",cnt);
    }
    return 0;
}
