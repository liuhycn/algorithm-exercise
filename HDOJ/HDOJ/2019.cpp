//
//  2019.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/29.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    
    pp();
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if(n == 0 && m == 0)
        {
            break;
        }
        int buf[1000] = {0};
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&buf[i]);
        }
        buf[n] = m;
        sort(buf,buf+n+1);
        for(int i = 0;i<=n;i++)
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
