//
//  2-sum.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/4.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int buf[10001];

int main()
{
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        memset(buf, 0, sizeof(buf));
        map<int, int>mymap;
        int m;
        scanf("%d",&m);
        for (int i = 0;i<n;i++)
        {
            scanf("%d",&buf[i]);
            mymap[buf[i]] = i;
        }
        for(int i = 0;i<n;i++)
        {
            int tar = m - buf[i];
            if(mymap.count(tar) == 1 && mymap[tar] != i)
            {
                printf("%d %d\n",i+1,mymap[tar]+1);
            }
        }
    }
    return 0;
}
