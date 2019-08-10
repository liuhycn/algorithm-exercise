//
//  830.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/7.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "../基础算法/Header.h"

int n;
int stk[100001];
int tt;

int main()
{
    pp();
    tt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        while (tt != 0 && stk[tt - 1] >= x) tt --;
        if (tt == 0)
            printf("-1 ");
        else
            printf("%d ", stk[tt - 1]);
        
        stk[tt++] = x;
    }
    return 0;
}
