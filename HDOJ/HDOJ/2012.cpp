//
//  2012.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

bool buf[2592];

void init()
{
    for(int i = 2;i<=2591;i++)
    {
        buf[i] = true;
    }
    buf[1] = false;
    int bound = (int)(sqrt(2592)+1);
    for (int i = 2;i<=bound;i++)
    {
        if(buf[i] == false)
        {
            continue;
        }
        else
        {
            for(int j = i*i;j<=2591;j = j+i)
            {
                buf[j] = false;
            }
        }
    }
    
}
int F(int x)
{
    return x*x+x+41;
}
int main()
{
    int n,m;
    pp();
    init();
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if(m == 0 && n ==0)
        {
            break;
        }
        int flag = 0;
        for(int i = n;i<=m;i++)
        {
            if(buf[F(i)] == true)
            {
                continue;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        printf(flag == 0 ? "OK\n" : "Sorry\n");
    }
    return 0;
}
