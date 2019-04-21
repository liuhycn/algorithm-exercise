//
//  merge-search-set.cpp
//  algorithm-exercise
//
//  Created by Hongyan Liu on 2019/4/21.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int citys[1001] = {0};

int findroot(int x)
{
    if(citys[x] == -1)
    {
        return x;
    }
    else
    {
        int temp = findroot(citys[x]);
        citys[x] = temp;
        return temp;
    }
}
void merge(int x,int y)
{
    citys[y] = x;
}

int main()
{
    int n,m;
    printf("welcome\n");
    while (scanf("%d",&n)!=EOF)
    {
        if(n == 0)
        {
            break;
        }
        memset(citys, -1, sizeof(citys));
        scanf("%d",&m);
        for (int i = 0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int root1 = findroot(x);
            int root2 = findroot(y);
            if(root1 != root2)                      //属于同一个并查集的元素不用合并
            {
                merge(root1,root2);
            }
        }
        int ans = 0;
        for (int i = 1; i<=n;i++)
        {
            if(citys[i] == -1)
            {
                ans++;
            }
        }
        printf("%d\n",ans - 1);
    }
    return 0;
}
