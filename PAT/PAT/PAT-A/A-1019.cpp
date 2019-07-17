//
//  A-1019.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    pp();
    int n,b;
    scanf("%d%d",&n,&b);
    int ans[32] = {0};
    int cnt = 0;
    int flag = 1;
    if (n == 0)
    {
        ans[0] = 0;
        cnt = 1;
    }
    while (n != 0)
    {
        ans[cnt++] = n % b;
        n = n / b;
    }
    int i = 0;
    int j = cnt - 1;
    while (i < j)
    {
        if(ans[i] != ans[j])
        {
            flag = 0;
            break;
        }
        i++;
        j--;
    }
    if (flag == 1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    for (int i = cnt-1;i>=0;i--)
    {
        printf("%d",ans[i]);
        if(i != 0)
        {
            printf(" ");
        }
    }
    return 0;
}
