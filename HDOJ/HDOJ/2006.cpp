//
//  2006.cpp
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
        int ans = 1;
        for (int i = 0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(x%2 == 1)
            {
                ans = ans * x;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
