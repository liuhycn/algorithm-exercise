//
//  factorial-prime-decomposition.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/19.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int primeSize = 0;
int prime[1000] = {0};
bool mark[1000];

int cnt1[1000] = {0};
int cnt2[1000] = {0};

void init()
{
    memset(mark, true, sizeof(mark));
    for(int i = 2 ;i<1001;i++)
    {
        if(mark[i] == false)
        {
            continue;
        }
        else
        {
            prime[primeSize++] = i;
            for(int j = i*i;j<1001;j+=i)
            {
                mark[j] = false;
            }
        }
    }
}

int main()
{
    //printf("welcome\n");
    init();
    int n,a;
    while (scanf("%d%d",&n,&a)!=EOF)
    {
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for(int i = 0; i < primeSize; i++)                  //decompose n!
        {
            int t = n;
            while(t/prime[i] != 0)
            {
                cnt1[i] = cnt1[i] + t/prime[i];
                t = t/prime[i];
            }
        }
        int index = 0;
        while(a != 1)                                       //decompose a
        {
            if(a%prime[index] == 0)
            {
                a = a / prime[index];
                cnt2[index]++;
            }
            else
            {
                index++;
            }
        }
        int ans = 123123123;
        for(int i = 0; i < primeSize; i++)
        {
            if(cnt1[i] >= 0 && cnt2[i] == 0)
            {
                continue;
            }
            else if (cnt1[i] < cnt2[i])
            {
                ans = 0;
                break;
            }
            else
            {
                if(ans > cnt1[i]/cnt2[i])
                {
                    ans = cnt1[i]/cnt2[i];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
