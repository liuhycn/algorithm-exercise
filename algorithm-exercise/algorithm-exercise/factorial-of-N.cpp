//
//  factorial-of-N.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/19.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//
//计算阶乘只需要一个int数值与bigIteger相乘
#include "Header.h"

struct bigInteger
{
    int digit[1000];
    int size;
    void init()
    {
        memset(digit, 0, sizeof(digit));
        size = 0;
    }
    void set(char* str)
    {
        int length = int(strlen(str));
        int right = 1;
        int cnt = 0;
        int tmp = 0;
        for (int i = length - 1; i >= 0; i--)
        {
            tmp = tmp + (str[i]-'0')*right;
            cnt++;
            right = right * 10;
            if(cnt == 4 || i == 0)
            {
                digit[size++] = tmp;
                cnt = 0;
                right = 1;
                tmp = 0;
            }
        }
    }
    void outPut()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            if(i == size - 1)
            {
                printf("%d",digit[i]);
            }
            else
            {
                printf("%04d",digit[i]);
            }
        }
        printf("\n");
    }
    bigInteger operator * (const int &b)const
    {
        bigInteger ans;
        ans.init();
        int carry = 0;
        for (int i = 0; i<size; i++)
        {
            int temp = b * digit[i] + carry;
            carry = temp / 10000;
            ans.digit[ans.size++] = temp % 10000;
        }
        if(carry != 0)
        {
            ans.digit[ans.size++] = carry;
        }
        return ans;
    }
};

int main()
{
    int n;
    //printf("welcome\n");
    while (scanf("%d", &n)!=EOF)
    {
        bigInteger num;
        num.init();
        char c[1] = {'1'};
        num.set(c);
        for(int i = 2;i<=n;i++)
        {
            num = num * i;
        }
        num.outPut();
    }
    return 0;
}
