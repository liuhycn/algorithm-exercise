//
//  1197.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/28.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int shijinzhi(int x)
{
    int ans = 0;
    while (x!=0)
    {
        ans = ans + x%10;
        x = x / 10;
    }
    return ans;
}
int shierjinzhi(int x)
{
    int ans = 0;
    while (x!=0)
    {
        ans = ans + x%12;
        x = x / 12;
    }
    return ans;
}
int shiliujinzhi(int x)
{
    int ans = 0;
    while (x!=0)
    {
        ans = ans + x%16;
        x = x / 16;
    }
    return ans;
}
bool judge(int a,int b,int c)
{
    if(a == b && b == c)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    for(int i = 2992;i<=9999;i++)
    {
        int a = shijinzhi(i);
        int b = shierjinzhi(i);
        int c = shiliujinzhi(i);
        if(judge(a, b, c))
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
