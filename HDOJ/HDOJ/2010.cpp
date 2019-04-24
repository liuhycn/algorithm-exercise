//
//  2010.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/25.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

bool isShuixianhua(int x)
{
    bool ans = false;
    char str[3] = {0};
    sprintf(str,"%d",x);
    if((pow(str[0]-'0',3) + pow(str[1]-'0',3) + pow(str[2]-'0',3)) == x)
    {
        ans = true;
    }
    return ans;
}


int main()
{
    int m,n;
    pp();
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        int first = 0;
        int cnt = 0;
        for(int i = m;i<=n;i++)
        {
            if(isShuixianhua(i))
            {
                cnt++;
                if(first == 0)
                {
                    first = 1;
                    printf("%d",i);
                }
                else
                {
                    printf(" %d",i);
                }
            }
        }
        if(cnt == 0)
        {
            printf("no");
        }
        printf("\n");
    }
    return 0;
}
