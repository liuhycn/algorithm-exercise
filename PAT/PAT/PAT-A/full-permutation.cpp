//
//  full-permutation.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/1.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"
bool visit[11] = {0};
int ans[21] = {0};
int n;
void dfs(int index)
{
    if(index == n)
    {
        for(int i = 0;i<n;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    else
    {
        for(int i = 1;i<=n;i++)
        {
            if(visit[i] == false)
            {
                ans[index] = i;
                visit[i] = true;
                dfs(index+1);
                visit[i] = false;
            }
            else
            {
                continue;
            }
        }
    }
}

int main()
{
    pp();
    scanf("%d",&n);
    dfs(0);
    return 0;
}
