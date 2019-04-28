//
//  dp.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"
int weight[2001];

int main()
{
    int n,k;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        memset(weight,0,sizeof(weight));
        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&weight[i]);
        }
        for(int i = 0;i<k;i++)
        {
            
        }
    }
    return 0;
}
