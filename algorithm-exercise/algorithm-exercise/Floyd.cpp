//
//  Floyd.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/22.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int a[201][201];

void init(int n)
{
    for (int i =0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(i == j)a[i][j] = 0;
            else a[i][j] = 123123123;
        }
    }
}

int main()
{
    int n,m;
    pp();
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if(m ==0 && n ==0)
        {
            break;
        }
        init(n);
        for(int i = 0;i< m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[x][y] = min(z,a[x][y]);
            a[y][x] = min(z,a[y][x]);
        }
        for(int k = 0;k<n;k++)
        {
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
                }
            }
        }
        int src,dst;
        scanf("%d%d",&src,&dst);
        if(a[src][dst] == 123123123)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",a[src][dst]);
        }
    }
}
