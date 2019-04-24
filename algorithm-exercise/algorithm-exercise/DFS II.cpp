//
//  DFS II.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/24.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

bool visit[8][8];
char a[8][8];

int go[][2] =
{
    -1,0,
    0,-1,
    0,1,
    1,0
};

int n,m,t;
bool flag = 0;

bool BFS(int x,int y,int step)
{
    bool ans = false;
    for(int i = 0;i<4;i++)
    {
        
        int tx = x + go[i][0];
        int ty = y + go[i][1];
        if(tx < 0 || tx == n || ty < 0 || ty == m)
        {
            continue;
        }
        if(visit[tx][ty] == 1 || a[tx][ty] == 'X')
        {
            continue;
        }
        int tstep = step + 1;
        visit[tx][ty] = 1;
        if(tstep == t && a[tx][ty] != 'D')
        {
            visit[tx][ty] = 0;
            return false;
        }
        else if(a[tx][ty] == 'D' && tstep == t)
        {
            return true;
        }
        else if (tstep < t)
        {
            ans = BFS(tx, ty, tstep);
            if(ans == true)
            {
                return ans;
            }
            else
            {
                visit[tx][ty] = 0;
                continue;                   //回退的时候必须要还原visit
            }
        }
        
        
    }
    
    return ans;
}

void init()
{
    memset(a,0,sizeof(a));
    memset(visit, 0, sizeof(visit));
}
int sx,sy;
int dx,dy;
int main()
{
    pp();
    while (scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        if(n == 0 && m == 0 && t == 0)
        {
            break;
        }
        init();
        for (int i = 0; i< n;i++)
        {
            scanf("%s",a[i]);
        }
        for (int i =0; i<n; i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(a[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                    visit[i][j] = 1;
                    break;
                }
            }
        }
        for (int i =0; i<n; i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(a[i][j] == 'D')
                {
                    dx = i;
                    dy = j;
                    break;
                }
            }
        }
        if((dx+dy)%2 == (sx+sy+t)%2)
        {
            bool ans = BFS(sx,sy,0);
            if(ans == 1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
