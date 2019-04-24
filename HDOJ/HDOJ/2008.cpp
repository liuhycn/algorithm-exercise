//
//  2008.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/24.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        if(n == 0)
        {
            break;
        }
        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;
        for(int i =0;i<n;i++)
        {
            double x;
            scanf("%lf",&x);
            if(x == 0)
            {
                ans1++;
            }
            else if (x < 0)
            {
                ans2++;
            }
            else
            {
                ans3++;
            }
        }
        printf("%d %d %d\n",ans2,ans1,ans3);
    }
    return 0;
}
