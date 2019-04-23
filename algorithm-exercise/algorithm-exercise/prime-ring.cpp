//
//  prime-ring.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/23.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

bool visit[18];
int ans[18];
int num;

void init()
{
    memset(visit, 0, sizeof(visit));
    memset(ans, 0, sizeof(ans));
}

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};

bool isPrime(int x)
{
    bool ans = false;
    for(int i = 0;i< 13;i++)
    {
        if(x == prime[i])
        {
            ans = true;
            break;
        }
    }
    return ans;
}

void DFS(int n)                                         //n为已经找到环的长度
{
    if(n == num)
    {
        if(isPrime(1+ans[num]))
        {
            for(int i = 1;i<=num;i++)
            {
                if(i != 1)
                {
                    printf(" ");
                }
                printf("%d",ans[i]);
            }
            printf("\n");
        }
        return ;
    }
    for(int i = 2;i<=num;i++)
    {
        if(visit[i] == 0 && isPrime(ans[n]+i))
        {
            visit[i] = 1;
            ans[n+1] = i;
            DFS(n+1);
            visit[i] = false;                       //当前点搜索之后，标记为f未出现
        }
    }
}

int caseNo = 1;
int main()
{
    pp();
    while (scanf("%d",&num)!=EOF)
    {
        init();
        printf("Case %d:\n",caseNo++);
        visit[1] = 1;
        ans[1] = 1;
        DFS(1);
        printf("\n");
    }
    return 0;
}
