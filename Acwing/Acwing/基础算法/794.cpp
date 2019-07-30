//
//  794.cpp
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
        printf("\n");
    }
    void setup(char nums[])
    {
        int len = (int)strlen(nums);
        int tmp = 0;
        int right = 1;
        int cnt = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            tmp += (nums[i] - '0') * right;
            cnt ++;
            right *= 10;
            if (i == 0 || cnt == 4)
            {
                digit[size++] = tmp;
                cnt = 0;
                right = 1;
                tmp = 0;
            }
        }
    }
};

bigInt div(bigInt a, int b, int &rem)
{
    bigInt ans;
    ans.init();
    int first = 0;
    for (int i = a.size - 1; i >= 0; i--)
    {
        int tmp = (a.digit[i] + rem * 10000) / b;
        if (tmp == 0 && first == 0)
        {
            first = 1;
        }
        else
        {
            ans.digit[ans.size++] = tmp;
        }
        rem = (a.digit[i] + rem * 10000) % b;
    }
    for (int i = 0, j = ans.size - 1; i < j; i++, j--)
    {
        swap(ans.digit[i], ans.digit[j]);
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
    int ans = 0;
    bigInt c = div(a, b, ans);
    c.display();
    printf("%d", ans);
    return 0;
}
