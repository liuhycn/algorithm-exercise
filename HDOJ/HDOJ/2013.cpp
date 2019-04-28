//
//  2013.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int buf[31] = {0};

void init()
{
    buf[1] = 1;
    for(int i =2;i<=30;i++)
    {
        buf[i] = 2*(buf[i-1]+1);
    }
}


int main()
{
    int n;
    pp();
    init();
    while (scanf("%d",&n)!=EOF)
    {
        printf("%d\n",buf[n]);
    }
    return 0;
}
