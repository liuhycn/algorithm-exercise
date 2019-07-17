//
//  1012.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/5.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    int n;
    pp();
    scanf("%d",&n);
    int buf[1001];
    int ans[6] = {0};
    int cnt[6] = {0};
    for (int i = 0; i<n; i++)
    {
        scanf("%d",&buf[i]);
        if(buf[i] % 5 == 0 && buf[i] % 2 == 0)
        {
            ans[1] += buf[i];
            cnt[1] ++;
        }
        else if (buf[i] % 5 == 1)
        {
            cnt[2] ++;
            if(cnt[2] % 2 == 0)
            {
                ans[2] = ans[2] - buf[i];
            }
            else
            {
                ans[2] = ans[2] + buf[i];
            }
        }
        else if (buf[i] % 5 == 2)
        {
            ans[3] ++;
            cnt[3] ++;
        }
        else if (buf[i] % 5 == 3)
        {
            ans[4] = ans[4] + buf[i];
            cnt[4] ++;
        }
        else if (buf[i] % 5 == 4)
        {
            if(buf[i] > ans[5])
            {
                ans[5] = buf[i];
                cnt[5] ++;
            }
        }
    }
    double ans4 = ans[4]*1.0 / cnt[4];
    for (int i = 1;i<=5;i++)
    {
        if (cnt[i] == 0)
        {
            printf("N");
        }
        else
        {
            if(i != 4)
                printf("%d",ans[i]);
            else
                printf("%.1lf",ans4);
        }
        if(i != 5)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
