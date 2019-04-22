//
//  BFS.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/22.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <math.h>

using namespace std;
struct node
{
    int a;
    int b;
    int c;
    int t;
};

int visit[50][50][50];
int a[50][50][50];
queue<node> Q;
void init()
{
    memset(visit,0,sizeof(visit));
    memset(a, 0, sizeof(a));
    while(!Q.empty())
    {
        Q.pop();
    }
}
int go[][3] =
{
    1,0,0,
    -1,0,0,
    0,1,0,
    0,-1,0,
    0,0,1,
    0,0,-1
};
int bfs(int x,int y,int z)
{
    while(!Q.empty())
    {
        node thisn = Q.front();
        Q.pop();
        for(int i = 0;i<6;i++)
        {
            int thisa = thisn.a + go[i][0];
            int thisb = thisn.b + go[i][1];
            int thisc = thisn.c + go[i][2];
            if(thisa <0 || thisa >=x||thisb<0||thisb>=y||thisc<0||thisc>=z)
            {
                continue;
            }
            if(visit[thisa][thisb][thisc] == 1 || a[thisa][thisb][thisc] == 1)
            {
                continue;
            }
            node newn;
            newn.t = thisn.t+1;
            newn.a = thisa;
            newn.b = thisb;
            newn.c = thisc;
            Q.push(newn);
            visit[newn.a][newn.b][newn.c] = 1;
            if(thisa == x-1 && thisb == y-1 && thisc == z-1)
            {
                return newn.t;
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for(int i = 0;i<n;i++)
        {
            init();
            int x,y,z,max_t;
            scanf("%d%d%d%d",&x,&y,&z,&max_t);
            for(int j = 0;j<x;j++)
            {
                for(int k = 0;k<y;k++)
                {
                    for(int m = 0;m<z;m++)
                    {
                        scanf("%d",&a[j][k][m]);
                    }
                }
            }
            node tmp;
            tmp.a = 0;
            tmp.b = 0;
            tmp.c = 0;
            tmp.t = 0;
            visit[0][0][0] = 1;
            Q.push(tmp);
            int ans = bfs(x, y, z);
            if(ans < max_t)
            {
                printf("%d\n",ans);
            }
            else
            {
                printf("-1\n");
            }
        }
    }
    return 0;
}
