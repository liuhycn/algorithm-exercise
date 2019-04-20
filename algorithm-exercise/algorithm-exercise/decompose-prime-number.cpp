//
//  decompose-prime-number.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/18.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int size = 0;
int prime[100001] = {0};
bool buf[100001];
void init()
{
    memset(buf,true,sizeof(buf));
    for (int i= 2; i < 100001; i++)
    {
        if(buf[i] == false)
        {
            continue;
        }
        else
        {
            prime[size++] = i;
            if(i>=1000) continue;
            for(int j = i*i;j<100001;j = j+i)
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
    while (scanf("%d",&n)!=EOF)
    {
        int index=0;
        int ans = 0;
        int flag = 0;
        while(n!=1)
        {
            if(n%prime[index] == 0)
            {
                ans++;
                n = n/prime[index];
            }
            else
            {
                index++;
            }
            if(index == size)                           //说明剩下的数字本身是一个质数
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1) printf("%d\n",ans+1);
        else printf("%d\n",ans);
    }
    return 0;
}
