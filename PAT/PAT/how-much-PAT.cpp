//
//  how-much-PAT.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/4.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

char buf[100001];
int sumP[100001];
int sumT[100001];

int main()
{
    pp();
    while (scanf("%s",buf)!=EOF)
    {
        memset(sumP, 0, sizeof(sumP));
        memset(sumT, 0, sizeof(sumT));
        int sum = 0;
        int length = (int)strlen(buf);
        for (int i = 0; i<length; i++)
        {
            if(buf[i] == 'P')
            {
                sum++;
            }
            else if (buf[i] == 'A')
            {
                sumP[i] = sum;
            }
        }
        sum = 0;
        for (int i = length - 1; i>=0; i--)
        {
            if(buf[i] == 'T')
            {
                sum++;
            }
            else if (buf[i] == 'A')
            {
                sumT[i] = sum;
            }
        }
        sum = 0;
        for (int i = 0; i<length; i++)
        {
            if(buf[i] == 'A')
            {
                sum = (sum + sumP[i] * sumT[i])%1000000007;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
