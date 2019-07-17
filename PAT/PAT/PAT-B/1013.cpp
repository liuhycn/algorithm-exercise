//
//  1013.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/16.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int primeBuf[1000001] = {0};
int filter[100001] = {0};
int indeX = 0;
void init()
{
    for (int i = 2; i < 1000001; i++)
    {
        if (filter[i] == 0)
        {
            primeBuf[indeX++] = i;
            if (indeX >= 10000) break;
            for (int j = i + i; j < 1000001; j = j + i)
            {
                filter[j] = 1;
            }
        }
    }
}

int main()
{
    pp();
    init();
    int m, n;
    scanf("%d%d", &m, &n);
    int cnt = 0;
    //int sum = n - m;
    for (int i = m - 1; i <= n - 1; i++)
    {
        if (cnt == 0)
            printf("%d", primeBuf[i]);
        else
            printf(" %d", primeBuf[i]);
        
        cnt++;
        if (cnt == 10 && i != n - 1)
        {
            cnt = 0;
            printf("\n");
        }
    }
    return 0;
}
