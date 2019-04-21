//
//  prim-algorithm.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/21.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//
// 用prim做的题中每两个地点是只有一条路的,而kruskal不管是多少条路都适用

#include "Header.h"

int a[55][55];

int main()
{
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        int b[55];
        int dist[55];
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j] == 0)
                {
                    a[i][j] = 123123123;
                }
            }
        }
        for(int i = 1;i<=n;i++)
        {
            b[i] = false;
        }
        b[1] = true;
        dist[1] = 123123123;
        for(int i =2;i<=n;i++)
        {
            dist[i] = a[1][i];
        }
        int ans = 0;
        for(int i = 2;i<=n;i++)
        {
            int index = 0;
            int min = 123132123;
            for (int j = 2;j<=n;j++)                            //找到当前集合z距离最近的节点
            {
                if(b[j] == false && dist[j] < min)
                {
                    index = j;
                    min = dist[j];
                }
            }
            if(index == 0)                                      //没找到
            {
                break;
            }
            else                                                //找到加入mst集合
            {
                b[index] = true;
                ans = ans + min;
            }
            for(int j = 2;j<=n;j++)                             //更新dist
            {
                if(a[index][j] < dist[j] && b[j] == false)
                {
                    dist[j] = a[index][j];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
