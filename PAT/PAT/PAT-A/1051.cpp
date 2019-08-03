//
//  1051.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/1.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


int nums[1001][1001];

vector<int> buf;
int n, m, k;
int visit[1001];
int flag = 0;
int main()
{
    
    pp();
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> nums[i][j];
    for (int i = 0; i < k; i++)
    {
        flag = 0;
        for (int j = 0; j < n; j++)
        {
            int x;
            x = nums[i][j];
            if (buf.empty() || buf[buf.size() - 1] != x)
            {
                if (visit[x] == 0)
                {
                    int index = 1;
                    while (index <= x)
                    {
                        if (visit[index] == 0)
                        {
                            visit[index] = 1;
                            buf.push_back(index);
                        }
                        index++;
                    }
                    if (buf.size() > m)
                    {
                        flag = 1;
                        break;
                    }
                    buf.pop_back();
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            else if (buf[buf.size() - 1] == x)
                buf.pop_back();
        }
        if (flag == 0)
            printf("YES\n");
        else
            printf("NO\n");
        buf.clear();
        memset(visit, 0, sizeof(visit));
    }
    
    return 0;
}
