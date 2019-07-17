//
//  A-1046.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/5.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int dist[100001];
int ans[100002];

int main()
{
    int n;
    pp();
    scanf("%d",&n);
    int sum = 0;
    for (int i = 1; i<=n; i++)
    {
        scanf("%d",&dist[i]);
        sum += dist[i];
        ans[i+1] = sum;
    }
    int m;
    scanf("%d",&m);
    for (int i = 0; i<m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x > y)
        {
            swap(x,y);
        }
        int kk = ans[y] - ans[x];
        kk = min(kk, sum - kk);
        printf("%d\n",kk);
    }
    return 0;
}
