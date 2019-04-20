//
//  Hexadecimal-conversion III.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/20.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

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
        int temp = 0;
        int cnt = 0;
        for (int i = length -1; i>=0;i--)
        {
            temp = temp + (str[i]-'0') * right;
            cnt++;
            right = right * 10;
            if(cnt == 4 || i == 0)
            {
                digit[size++] = temp;
                temp = 0;
                right = 1;
                cnt = 0;
            }
        }
    }
    void output()
    {
        for(int i = size -1; i>=0;i--)
        {
            if(i == size-1)
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
    bigInteger operator + (const int &x)const
    {
        bigInteger ans;
        ans.init();
        int carry = 0;
        int temp = digit[0] + x;
        carry  = temp / 10000;
        ans.digit[ans.size++] = temp % 10000;
        for(int i = 1;i<size;i++)
        {
            temp = digit[i] + carry;
            ans.digit[ans.size++] = temp %10000;
            carry = temp / 10000;
        }
        if(carry!=0)
        {
            ans.digit[ans.size++] = carry;
        }
        return ans;
    }
    bigInteger operator * (const int &x)const
    {
        bigInteger ans;
        ans.init();
        int carry = 0;
        for (int i = 0;i<size;i++)
        {
            int temp = digit[i] * x + carry;
            carry = temp / 10000;
            ans.digit[ans.size++] = temp % 10000;
        }
        if(carry != 0)
        {
            ans.digit[ans.size++] = carry;
        }
        return ans;
    }
    bigInteger operator / (const int &x)const
    {
        bigInteger ans;
        ans.init();
        int remainder = 0;
        for (int i = size - 1; i>=0;i--)
        {
            int temp = (remainder * 10000 + digit[i]) / x;
            remainder = (remainder * 10000 + digit[i]) % x;
            ans.digit[i] = temp;                                //直接赋值
        }
        for(int i = size -1; i>=0;i--)
        {
            if(ans.digit[i] != 0)
            {
                ans.size = i;
                break;
            }
        }
        ans.size ++;
        return ans;
    }
    int operator % (const int &x)const
    {
        int remainder = 0;
        for (int i = size - 1;i>=0;i--)
        {
            remainder = (remainder * 10000 + digit[i]) % x;
        }
        return remainder;
    }
};
int converter1(char c)
{
    int ans = 0;
    if (c >= '0' && c <= '9')
    {
        ans =  c - '0';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        ans =  c - 55;
    }
    else if (c >= 'a' && c <= 'z')
    {
        ans =  c - 87;
    }
    return ans;
}
char converter2(int a)
{
    char ans;
    if (a >= 0 && a <= 9)
    {
        ans =  a + '0';
    }
    else if (a >= 10 && a <= 35)
    {
        ans = a + 87;
    }
    return ans;
}

int main()
{
    printf("welcome\n");
    int m,n;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        char a[10000];
        char str[10000];
        scanf("%s",a);
        bigInteger num;
        num.init();
        int l = int(strlen(a));
        for(int i = 0;i<l;i++)
        {
            num = num * m;
            num = num + converter1(a[i]);
        }
        //num.output();
        memset(str, 0, sizeof(str));
        int size = 0;
        while (!(num.size == 1 && num.digit[0] == 0))           //size = 1 且 digit[0] = 0时，大数为0
        {
            int tmp = num % n;
            str[size++] = converter2(tmp);
            num = num / n;
        }
        for (int i = size -1 ;i>=0;i--)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
