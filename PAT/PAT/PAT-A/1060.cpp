//
//  1060.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/7/18.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int n;

string process(string str, int &e)
{
    while (str.length() > 0 && str[0] == '0')
        str.erase(str.begin());
    if (str[0] == '.')
    {
        str.erase(str.begin());
        while (str.length() > 0 && str[0] == '0')
        {
            str.erase(str.begin());
            e --;
        }
        // 0000.00000
        if (str.length() == 0) e = 0;
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '.')
            {
                str.erase(str.begin() + i);
                break;
            }
            e ++;
        }
        // 00000000
        if (str.length() == 0) e = 0;
    }
    if (str.length() >= n)
    {
        str = str.substr(0, n);
    }
    else
    {
        int cnt = n - str.length();
        for (int i = 0; i < cnt; i++)
        {
            str += '0'; // dynamic
        }
    }
    return str;
}
int main()
{
    pp();
    scanf("%d", &n);
    string num1;
    string num2;
    cin >> num1 >> num2;
    int e1 = 0;
    int e2 = 0;
    num1 = process(num1, e1);
    num2 = process(num2, e2);
    if (num1 == num2 && e1 == e2)
    {
        printf("YES 0.%s*10^%d", num1.c_str(), e1);
    }
    else
    {
        printf("NO 0.%s*10^%d 0.%s*10^%d", num1.c_str(), e1, num2.c_str(), e2);
    }
    return 0;
}
