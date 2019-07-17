//
//  1024.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"


struct bigInt
{
    int digit[1000];
    int size;
    bigInt()
    {
        memset(digit, 0, sizeof(digit));
        size = 0;
    }
    void setUp(char str[])
    {
        size = (int)strlen(str);
        for (int i = size - 1; i >= 0; i--)
        {
            digit[i] = str[i] - '0';
        }
    }
    void output()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            printf("%d", digit[i]);
        }
    }
    bool isPal()
    {
        bool ans = true;
        for (int i = 0, j = size - 1; i < j; i++, j--)
        {
            if (digit[i] != digit[j])
            {
                ans = false;
                break;
            }
        }
        return ans;
    }
};

bigInt reverse(bigInt a)
{
    bigInt b;
    b.size = a.size;
    int index = b.size;
    int first = 0;
    for (int i = 0; i < a.size; i++)
    {
        if (first == 0)
        {
            if (a.digit[i] == 0)
            {
                b.size--;
                index--;
            }
            else
            {
                b.digit[--index] = a.digit[i];
                first = 1;
            }
        }
        else
        {
            b.digit[--index] = a.digit[i];
        }
    }
    return b;
}

bigInt add (bigInt a, bigInt b)
{
    bigInt c;
    int length = max(a.size, b.size);
    int inc = 0;
    int tmp = 0;
    for (int i = 0; i < length; i++)
    {
        tmp = a.digit[i] + b.digit[i] + inc;
        inc = tmp / 10;
        c.digit[c.size++] = tmp % 10;
    }
    if (inc > 0)
    {
        c.digit[c.size++] = inc;
    }
    return c;
}

int main ()
{
    pp();
    char nums[31] = {0};
    int t = 0;
    scanf("%s%d", nums, &t);
    int cnt = 0;
    bigInt a;
    a.setUp(nums);
    while (cnt < t && a.isPal() == false)
    {
        bigInt b = reverse(a);
        a = add(a, b);
        cnt++;
    }
    a.output();
    printf("\n%d", cnt);
    return 0;
}
