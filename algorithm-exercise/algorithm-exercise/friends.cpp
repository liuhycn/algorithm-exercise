//
//  friends.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/21.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int friends[10000001];

int sum[10000001];

int findroot(int x)
{
    if(friends[x] == -1)
    {
        return x;
    }
    else
    {
        int temp = findroot(friends[x]);
        friends[x] = temp;
        return temp;
    }
}

void merge(int x,int y)
{
    friends[y] = x;
    sum[x] = sum[x] + sum[y];
}

int main()
{
    int n;
    //printf("welcome\n");
    while (scanf("%d",&n)!=EOF)
    {
        memset(friends, -1, sizeof(friends));
        for(int i = 1;i<10000001;i++)
        {
            sum[i] = 1;
        }
        int x,y;
        for(int i =0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            int root1 = findroot(x);
            int root2 = findroot(y);
            if(root1 != root2)
            {
                merge(root1,root2);
            }
        }
        int ans = 1;
        for(int i = 1;i<10000001;i++)
        {
            if(friends[i] == -1 && sum[i] > ans)
            {
                ans = sum[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
