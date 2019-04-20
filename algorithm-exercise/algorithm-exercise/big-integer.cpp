//
//  big-integer.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/19.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

struct bigInteger
{
    int digit[1000];                        //a cell contain 4 digits
    int size;
    void init()
    {
        memset(digit,0,sizeof(digit));
        size = 0;
    }
    void setup(char* str)
    {
        int cnt = 0;
        int length = int(strlen(str));
        int tmp = 0;
        int right = 1;
        for (int i = length - 1; i >= 0; i--)
        {
            tmp = tmp + (str[i]-'0') * right;
            cnt++;
            right = right * 10;
            if(cnt == 4 || i == 0)
            {
                digit[size++] = tmp;
                right = 1;
                cnt = 0;
                tmp = 0;
            }
        }
    }
    void output()
    {
        for(int i = size-1;i>=0;i--)
        {
            if(i == size-1)
            {
                printf("%d",digit[i]);                              //g高位不用补0
            }
            else
            {
                printf("%04d",digit[i]);                            //低位不足四位是要用前导0补足
            }
        }
        printf("\n");
    }
    bigInteger operator + (const bigInteger &b)const
    {
        bigInteger ans;
        ans.init();
        int carry = 0;
        int i;
        for (i = 0; i<size || i < b.size; i++)
        {
            ans.digit[i] = digit[i] + b.digit[i] + carry;
            carry = ans.digit[i] / 10000;
            ans.digit[i] = ans.digit[i] % 10000;
            ans.size++;
        }
        if (carry != 0)
        {
            ans.digit[i] = carry;
            ans.size++;
        }
        return ans;
    }
};

int main()
{
    char a[1001] = {0};
    char b[1001] = {0};
    //printf("welcome\n");
    while (scanf("%s%s",a,b)!=EOF)
    {
        bigInteger num1;
        bigInteger num2;
        num1.init();
        num2.init();
        num1.setup(a);
        num2.setup(b);
        //num1.output();
        //num2.output();
        num1 = num1 + num2;
        num1.output();
    }
    return 0;
}
