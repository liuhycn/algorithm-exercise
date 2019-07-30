//
//  793.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/7/27.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

struct bigInt
{
    int digit[100001];
    int size;
    void init()
    {
        size = 0;
        memset(digit, 0, sizeof(digit));
    }
    void setup(char nums[])
    {
        int len = (int)strlen(nums);
        int tmp = 0;
        int right = 1;
        int cnt = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            tmp += right * (nums[i] - '0');
            cnt ++;
            right *= 10;
            if (i == 0 || cnt == 4)
            {
                right = 1;
                cnt = 0;
                digit[size++] = tmp;
                tmp = 0;
            }
        }
    }
    void display()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            if (i == size - 1)
                printf("%d", digit[i]);
            else
                printf("%04d", digit[i]);
        }
    }
};

bigInt mul(bigInt a, int b)
{
    bigInt ans;
    ans.init();
    int inc = 0;
    for (int i = 0; i < a.size; i++)
    {
        int tmp = a.digit[i] * b + inc;
        inc = tmp / 10000;
        ans.digit[ans.size++] = tmp % 10000;
    }
    while (inc != 0)
    {
        ans.digit[ans.size++] = inc % 10000;
        inc = inc / 10000;
    }
    return ans;
}

int main()
{
    pp();
    bigInt a;
    a.init();
    char nums[100001];
    scanf("%s", nums);
    a.setup(nums);
    int b;
    scanf("%d", &b);
    bigInt c = mul(a, b);
    c.display();
    return 0;
}
