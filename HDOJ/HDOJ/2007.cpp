//
//  2007.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/24.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//


#include "Header.h"
int main()
{
    int n,m;
    pp();
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int ans1 = 0;
        int ans2 = 0;
        if(n > m)
        {
            swap(n, m);
        }
        for (int i = n;i<=m;i++)
        {
            if(i%2 == 0)
            {
                ans1 = ans1 + pow(i,2);
            }
            else
            {
                ans2 = ans2 + pow(i,3);
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
