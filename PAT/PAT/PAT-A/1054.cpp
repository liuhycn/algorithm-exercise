//
//  1054.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/31.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

#define M 801
#define N 601

map<int, int> mymap;

int buf[N][M];

int main()
{
    pp();
    int n ,m;
    int ans = 0;
    
    scanf("%d%d", &n, &m);
    int cnt = (n * m) >> 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &buf[i][j]);
            mymap[buf[i][j]] ++;
            if (mymap[buf[i][j]] > cnt)
                ans = buf[i][j];
        }
    
    printf("%d", ans);
    return 0;
}
