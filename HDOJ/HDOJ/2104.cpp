//
//  2104.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int gcd(int a,int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

int main()
{
    int n,m;
    pp();
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if(n == -1 && m == -1)
        {
            break;
        }
        if(gcd(n,m) == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("POOR Haha\n");
        }
    }
    return 0;
}
