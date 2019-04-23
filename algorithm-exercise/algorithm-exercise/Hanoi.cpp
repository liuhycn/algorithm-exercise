//
//  Hanoi.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/22.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

long long int hanoi(int n)                          //汉诺塔问题可能会爆int，所以用long long
{
    if(n == 1) return 2;
    return 3*hanoi(n-1) + 2;
}

int main()
{
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",hanoi(n));
    }
    return 0;
}
