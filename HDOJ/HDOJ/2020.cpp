//
//  2020.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/29.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

bool cmp(int x,int y)
{
    if(abs(x) > abs(y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

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
        int buf[1000] = {0};
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&buf[i]);
        }
        sort(buf,buf+n,cmp);
        for(int i = 0;i<n;i++)
        {
            if(i == 0)
            {
                printf("%d",buf[i]);
            }
            else
            {
                printf(" %d",buf[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
