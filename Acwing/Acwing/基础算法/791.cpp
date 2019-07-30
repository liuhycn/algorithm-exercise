//
//  791.cpp
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
    void setup(char str[])
    {
        int len = (int)strlen(str);
        int cnt = 0;
        int right = 1;
        int tmp = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            tmp += (str[i] - '0') * right;
            cnt ++;
            right *= 10;
            if (cnt == 4 || i == 0)
            {
                digit[size++] = tmp;
                tmp = 0;
                cnt = 0;
                right = 1;
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
        printf("\n");
    }
};

bigInt add(bigInt a, bigInt b)
{
    bigInt ans;
    ans.init();
    int inc = 0;
    int len = max(a.size, b.size);
    for (int i = 0; i < len; i++)
    {
        int tmp = a.digit[i] + b.digit[i] + inc;
        ans.digit[ans.size++] = tmp % 10000;
        inc = tmp / 10000;
    }
    if (inc != 0)
        ans.digit[ans.size++] = inc;
    return ans;
}


int main()
{
    pp();
    bigInt a, b;
    a.init();
    b.init();
    char nums[100001];
    scanf("%s", nums);
    a.setup(nums);
    scanf("%s", nums);
    b.setup(nums);
    bigInt c = add(a, b);
    c.display();
    return 0;
}
