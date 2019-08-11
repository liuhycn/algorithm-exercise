//
//  844.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/11.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int m[101][101];
int visit[101][101];
int qx[100001];
int qy[100001];
int d[100001];
int hh, tt;
int n, mm;
int ans;
int go[4][2] =
{
    -1, 0,
    1, 0,
    0, -1,
    0, 1
};

int main()
{
    pp();
    scanf("%d%d", &n, &mm);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= mm; j++)
            scanf("%d", &m[i][j]);
    
    hh = 0;
    tt = -1;
    tt ++;
    qx[tt] = 1;
    qy[tt] = 1;
    d[tt] = 0;
    
    while (hh <= tt)
    {
        int x = qx[hh];
        int y = qy[hh];
        int dist = d[hh];
        hh ++;
        /********************/
        if (visit[x][y] == 0)
            visit[x][y] = 1;
        else continue;
        /********************/
        if (x == n && y == mm)
        {
            ans = dist;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + go[i][0];
            int ny = y + go[i][1];
            if (visit[nx][ny] == 1 || nx < 1 || nx > n || ny < 1 || ny > mm || m[nx][ny] == 1) continue;
            tt++;
            qx[tt] = nx;
            qy[tt] = ny;
            d[tt] = dist + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
