//
//  1032.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/6.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


int buf[100001];


int main()
{
    pp();
    memset(buf, 0, sizeof(buf));
    int n;
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
    {
        int index;
        int val;
        scanf("%d%d",&index,&val);
        buf[index] += val;
    }
    int max = -1;
    int maxi = 0;
    for (int i = 0;i<100000;i++)
    {
        if(buf[i] > max)
        {
            maxi = i;
            max = buf[i];
        }
    }
    printf("%d %d\n",maxi,max);
    return 0;
}
