//
//  875.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/12.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int n;


long long int helper(int a, int b, int p)
{
    if (b == 0) return 1;
    if (b == 1) return a % p;
    
    long long int tmp;
    if (b % 2 == 1)
    {
        tmp = helper(a, b >> 1, p);
        /***************************/
        return tmp * tmp % p * a % p;
        /***************************/
    }
    else
    {
        tmp = helper(a, b >> 1, p);
        return tmp * tmp % p;
    }
    
    return tmp;
}

int main()
{
    pp();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        printf("%lld\n", helper(a % p, b, p));
    }
    return 0;
}
