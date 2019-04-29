//
//  2018.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


//动物繁殖问题一般用斐波那契数列

long long int buf[56];
void init()
{
    memset(buf, 0, sizeof(buf));
    buf[1] = 1;
    buf[2] = 2;
    buf[3] = 3;
    for(int i = 4;i<=55;i++)
    {
        buf[i] = buf[i -3]+buf[i-1];
    }
}

int main()
{
    int n;
    pp();
    init();
    while (scanf("%d",&n)!=EOF)
    {
        if(n ==0 )
        {
            break;
        }
        printf("%lld\n",buf[n]);
    }
    
    return 0;
}
