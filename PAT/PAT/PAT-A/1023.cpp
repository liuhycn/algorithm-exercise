//
//  1023.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int buf[10] = {0};

struct bigInt
{
    int size;
    int digit[1000];
    bigInt()
    {
        size = 0;
        memset(digit, 0, sizeof(digit));
    }
    void output()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            if (i == size - 1)
                printf("%d" ,digit[i]);
            else
                printf("%04d" ,digit[i]);
        }
        if (size == 0)
            printf("0");
    }
    void setUp(char str[])
    {
        int length = (int)strlen(str);
        int right = 1;
        int tmp  = 0;
        int cnt = 0;
        for (int i = length - 1; i >= 0; i--)
        {
            tmp = tmp + right * (str[i] - '0');
            right = right * 10;
            cnt ++;
            if (cnt == 4 || i == 0)
            {
                digit[size++] = tmp;
                right = 1;
                cnt = 0;
                tmp = 0;
            }
        }
    }
};

bigInt mul (bigInt a, int b)
{
    bigInt c;
    int tmp = 0;
    int inc = 0;
    for (int i = 0; i < a.size; i++)
    {
        tmp = a.digit[i] * b + inc;
        //printf("%d*%d = %d\n", a.digit[i], b, tmp);
        inc = tmp / 10000;
        c.digit[c.size++] = tmp % 10000;
    }
    if (inc > 0)
    {
        c.digit[c.size++] = inc;
    }
    return c;
}

int main()
{
    pp();
    bigInt a;
    char nums[21] = {0};
    scanf("%s", nums);
    for (int i = 0; i < strlen(nums); i++)
    {
        buf[nums[i] - '0']++;
    }
    a.setUp(nums);
    //a.output();
    //printf("\n");
    bigInt c = mul(a, 2);
    
    int flag = 0;
    char numsbuf[22] = {0};
    for (int i = c.size - 1; i >= 0; i--)
    {
        if (i == c.size - 1)
        {
            sprintf(numsbuf, "%d" ,c.digit[i]);
            for (int j = 0; j < strlen(numsbuf); j++)
            {
                buf[numsbuf[j] - '0'] --;
            }
        }
        else
        {
            sprintf(numsbuf, "%04d" ,c.digit[i]);
            for (int j = 0; j < strlen(numsbuf); j++)
            {
                buf[numsbuf[j] - '0'] --;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (buf[i] != 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("Yes\n");
    else
        printf("No\n");
    c.output();
    return 0;
}
