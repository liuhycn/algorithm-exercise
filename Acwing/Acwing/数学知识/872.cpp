//
//  872.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/12.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


int gcd(int a, int b)
{
    if (!b) return a;
    else return gcd(b, a % b);
}

int n;

int main()
{
    pp();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}
