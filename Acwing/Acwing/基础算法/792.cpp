//
//  792.cpp
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
    void setup(char str[])
    {
        int len = (int)strlen(str);
        int right = 1;
        int tmp = 0;
        int cnt = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            tmp += (str[i] - '0') * right;
            cnt ++;
            right *= 10;
            if (cnt == 4 || i == 0)
            {
                digit[size++] = tmp;
                tmp = 0;
                right = 1;
                cnt = 0;
            }
        }
    }
};

int cmp(bigInt a, bigInt b)
{
    if (a.size != b.size)
    {
        if (a.size > b.size)
            return 1;
        else
            return -1;
    }
    else
    {
        for (int i = a.size - 1; i >= 0; i--)
        {
            if (a.digit[i] != b.digit[i])
            {
                if (a.digit[i] > b.digit[i])
                    return 1;
                else
                    return -1;
            }
        }
    }
    return 0;
}

bigInt sub(bigInt a, bigInt b)
{
    bigInt ans;
    ans.init();
    int inc = 0;
    for (int i = 0; i < a.size; i++)
    {
        int tmp = a.digit[i] - inc - b.digit[i];
        if (tmp < 0)
        {
            inc = 1;
            tmp += 10000;
        }
        else
            inc = 0;
        ans.digit[ans.size++] = tmp;
    }
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
    if (cmp(a, b) == 0)
    {
        printf("0");
        return 0;
    }
    else if (cmp(a, b) == -1)
    {
        swap(a, b);
        printf("-");
    }
    bigInt c = sub(a, b);
    c.display();
    return 0;
}
