//
//  wrong-letter.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//
//n个数，每个数有一个自己不能去的位置
#include "Header.h"

long long int buf[21];

void init()
{
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 1;
    for(int i = 3;i<=20;i++)
    {
        buf[i] = (i -1)*buf[i-1]+(i-1)*buf[i-2];
    }
}

int main()
{
    int n;
    init();
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",buf[n]);
    }
    return 0;
}
