//
//  2017.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        for(int i = 0;i<n;i++)
        {
            char buf[1001] = {0};
            scanf("%s",buf);
            int len = strlen(buf);
            int sum = 0;
            for (int i = 0;i<len;i++)
            {
                if(buf[i] >= '0' && buf[i] <='9')
                {
                    sum ++;
                }
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
