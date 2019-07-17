//
//  1063.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


void pp()
{
    printf("welcome\n");
}
int main()
{
    pp();
    int n;
    scanf("%d", &n);
    set<int> s[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int cnt;
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; j++)
        {
            int a;
            scanf("%d", &a);
            s[i].insert(a);
        }
    }
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int x, y;
        int same = 0;
        scanf("%d%d", &x, &y);
        if (s[x].size() <= s[y].size())
        {
            set<int>::iterator it = s[x].begin();
            for (it = s[x].begin(); it != s[x].end(); it++)
            {
                if (s[y].find(*it) != s[y].end())
                {
                    same++;
                }
            }
        }
        else
        {
            set<int>::iterator it = s[y].begin();
            for (it = s[y].begin(); it != s[y].end(); it++)
            {
                if (s[x].find(*it) != s[x].end())
                {
                    same++;
                }
            }
        }
        double rate = 1.0 * same / (s[x].size() + s[y].size() - same);
        rate = rate * 100;
        printf("%.1lf", rate);
        printf("%%\n");
    }
    return 0;
}
