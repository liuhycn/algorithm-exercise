//
//  DFS.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/23.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

char a[101][101];                           //char型二维数组，用%s按行输入
bool visit [101][101];
int n,m;
void init()
{
    memset(a,'\0',sizeof(a));
    memset(visit,0,sizeof(visit));
}

int go[][2] =                               //注意不要回到自身
{
    -1,-1,
    -1,0,
    -1,1,
    0,-1,
    0,1,
    1,-1,
    1,0,
    1,1
};
void DFS(int x,int y)
{
    for(int i = 0;i<=7;i++)
    {
        int thisx = x + go[i][0];
        int thisy = y + go[i][1];
        if(thisx <1 || thisx > n || thisy <1 || thisy > m)
        {
            continue;
        }
        if(a[thisx][thisy] == '*' || visit[thisx][thisy] == 1)
        {
            continue;
        }
        visit[thisx][thisy] = 1;
        
        DFS(thisx,thisy);
        
    }
    return;
}

int main()
{
    pp();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if (m ==0&&n ==0 )
        {
            break;
        }
        init();
        for (int i =1; i<=n; i++)
        {
            scanf("%s",a[i]+1);
        }
        int sum = 0;
        for (int i =1; i <=n; i++)
        {
            for (int j =1; j<=m; j++)
            {
                if(a[i][j] == '@' && visit[i][j] == 0)
                {
                    sum++;
                    DFS(i,j);
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
