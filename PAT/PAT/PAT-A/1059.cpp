//
//  1059.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/16.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int filter[10001] = {0};
int primeCnt = 0;

int primeBuf[1001] = {0};

void init()
{
    for (int i = 2; i < 10001; i++)
    {
        if (filter[i] == 0)
        {
            primeBuf[primeCnt++] = i;
            if (primeCnt == 1001) break;
            for (int j = i + i; j < 10001; j = j + i)
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
    long long int n;
    scanf("%ld", &n);
    printf("%ld=", n);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    int k[1001] = {0};
    for (int i = 0; i < 1001; i++)
    {
        while (n % primeBuf[i] == 0)
        {
            k[i] ++;
            n = n / primeBuf[i];
            if (n == 1) break;
        }
        if (n == 1) break;
    }
    int first = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (k[i] > 1)
        {
            if (first == 0)
            {
                printf("%d^%d", primeBuf[i], k[i]);
                first = 1;
            }
            else
            {
                printf("*%d^%d", primeBuf[i], k[i]);
            }
        }
        else if (k[i] == 1)
        {
            if (first == 0)
            {
                printf("%d", primeBuf[i]);
                first = 1;
            }
            else
            {
                printf("*%d", primeBuf[i]);
            }
            
        }
    }
    
    return 0;
}
