//
//  2015.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int buf[101];

void init()
{
    for(int i =1,j = 2;i<=100;i++,j=j+2)
    {
        buf[i] = j;
    }
}

int main()
{
    int n,m;
    pp();
    init();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int index = 1;
        while (n > 0)
        {
            if(n>m)
            {
                int sum = 0;
                for(int i = 0;i<m;i++)
                {
                    sum = sum + buf[index++];
                }
                printf("%d ",sum/m);
            }
            else
            {
                int sum = 0;
                for(int i = 0;i<n;i++)
                {
                    sum = sum + buf[index++];
                }
                printf("%d\n",sum/n);
            }
            n = n-m;
        }
    }
    return 0;
}
