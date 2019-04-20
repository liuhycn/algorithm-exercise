//
//  select-prime-number.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/18.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

bool buf[10001];
int prime[10001] = {0};
int size = 0;

void init()
{
    memset(buf,true,sizeof(buf));
    for (int i = 2;i<10001;i++)
    {
        if(buf[i] == false)
        {
            continue;
        }
        else
        {
            prime[size++] = i;
            for(int j= i*i ;j < 10001;j = j+i)         //一次翻一倍
            {
                buf[j] = false;
            }
        }
    }
}

int main()
{
    int n;
    //printf("welcome\n");
    init();
    while(scanf("%d",&n)!=EOF)
    {
        bool firstout = 0;
        for(int i = 0;i<size;i++)
        {
            if(prime[i] < n)
            {
                if(prime[i]%10 == 1)
                {
                    if(firstout == 0)
                    {
                        firstout = 1;
                        printf("%d",prime[i]);
                    }
                    else
                    {
                        printf(" %d",prime[i]);
                    }
                }
            }
            else
            {
                break;
            }
        }
        if(firstout == 0)
        {
            printf("-1\n");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}
