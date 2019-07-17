//
//  bigInt.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "PAT/PAT-A/Header.h"

struct bigInt
{
    int size;
    int digit[1000];
    bigInt()
    {
        memset(digit, 0, sizeof(digit));
        size = 0;
    }
    void setUp(char str[])
    {
        int tmp = 0;
        int right = 1;
        int cnt = 0;
        //size = (int)strlen(str);
        int length = (int)strlen(str);
        for (int i = length - 1; i >= 0; i--)
        {
            int cur = str[i] - '0';
            tmp = tmp + cur * right;
            right = right * 10;
            cnt++;
            if (cnt == 4 || i == 0)
            {
                digit[size++] = tmp;
                right = 1;
                tmp = 0;
                cnt = 0;
            }
        }
    }
    void output()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            if (i == size - 1)
                printf("%d", digit[i]);
            else
                printf("%04d", digit[i]);
        }
        printf("\n");
    }
    
};
bigInt add (bigInt a, bigInt b)
{
    int inc = 0;
    bigInt c;
    int length = max(a.size, b.size);
    for (int i = 0; i < length; i++)
    {
        int sum = a.digit[i] + b.digit[i] + inc;
        inc = sum / 10000;
        c.digit[c.size++] = sum % 10000;
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
    char num1[1000] = {0};
    char num2[1000] = {0};
    scanf("%s", num1);
    scanf("%s", num2);
    bigInt bi1;
    bigInt bi2;
    bi1.setUp(num1);
    bi2.setUp(num2);
    bi1.output();
    bi2.output();
    add(bi1, bi2).output();
    return 0;
}
