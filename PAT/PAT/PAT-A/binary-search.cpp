//
//  binary-search.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/4.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int buf[200];

int main()
{
    int n;
    pp();
    while(scanf("%d",&n)!=EOF)
    {
        memset(buf, 0, sizeof(buf));
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&buf[i]);
        }
        sort(buf,buf+n);
        int tar;
        scanf("%d",&tar);
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int mid = left + (right-left)/2;
            if(buf[mid] >= tar)
            {
                right = mid;
            }
            else if (buf[mid] < tar)
            {
                left = mid + 1;
            }
        }
        printf("%d ",left);
        left = 0;
        right = n - 1;
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(buf[mid] <= tar)
            {
                left = mid + 1;
            }
            else if (buf[mid] > tar)
            {
                right = mid;
            }
        }
        printf("%d\n",left);
    }
    return 0;
}
