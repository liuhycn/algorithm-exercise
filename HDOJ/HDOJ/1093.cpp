//
//  1093.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/23.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int n;
    //pp();
    while (scanf("%d",&n)!=EOF)
    {
        for(int i = 0;i<n;i++)
        {
            int m;
            scanf("%d",&m);
            int ans = 0;
            for (int i = 0;i<m;i++)
            {
                int x;
                scanf("%d",&x);
                ans = ans + x;
            }
            printf("%d\n",ans);
        }

    }
    return 0;
}


