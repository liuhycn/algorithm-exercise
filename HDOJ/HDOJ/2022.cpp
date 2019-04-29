//
//  2022.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/29.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int buf[1001][1001];

int main()
{
    int n,m;
    pp();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(buf,0,sizeof(buf));
        int x = 1;
        int y = 1;
        int max = 0;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                scanf("%d",&buf[i][j]);
                if(abs(buf[i][j]) > max)
                {
                    max = abs(buf[i][j]);
                    x = i;
                    y = j;
                }
            }
        }
        printf("%d %d %d\n",x,y,buf[x][y]);
    }
    return 0;
}
