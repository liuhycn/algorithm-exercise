//
//  1062.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/27.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

char buf[1000][1000];

int main()
{
    int n;
    pp();
    while (scanf("%d",&n)!=EOF)
    {
        getchar();
        for(int i =0;i<n;i++)
        {
            memset(buf, 0, sizeof(buf));
            char str[1001] = {0};
            gets(str);
            int length = strlen(str);
            int cnt = 0;
            int size = 0;
            for(int j= 0;j<length;j++)
            {
                if(str[j] == ' ')
                {
                    cnt++;
                    size = 0;
                }
                else
                {
                    buf[cnt][size++] = str[j];
                }
            }
            cnt++;
            for (int j = 0;j<cnt;j++)
            {
                reverse(buf[j], buf[j]+strlen(buf[j]));
                if(j == 0)
                {
                    printf("%s",buf[j]);
                }
                else
                {
                    printf(" %s",buf[j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
