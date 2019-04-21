//
//  toposort.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/21.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

vector<int> edge[501];

queue<int> Q;

int inDegree[501] = {0};

int main()
{
    int n,m;
    pp();
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if(n == 0 && m == 0)
        {
            break;
        }
        //scanf("%d",&m);
        memset(inDegree, 0, sizeof(inDegree));
        while (!Q.empty())
        {
            Q.pop();
        }
        for(int i = 0;i<n;i++)
        {
            edge[i].clear();
        }
        for(int i = 0; i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);                    //x-->y
            edge[x].push_back(y);
            inDegree[y]++;
        }
        for(int i = 0;i<n;i++)                      //保存入度为0的节点
        {
            if(inDegree[i] == 0)
            {
                Q.push(i);
            }
        }
        int cnt = 0;
        while(!Q.empty())
        {
            int temp = Q.front();
            Q.pop();
            cnt++;
            for(int i = 0;i<edge[temp].size();i++)
            {
                inDegree[edge[temp][i]]--;
                if(inDegree[edge[temp][i]] == 0)
                {
                    Q.push(edge[temp][i]);
                }
            }
            edge[temp].clear();
        }
        if(cnt != n)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
}
