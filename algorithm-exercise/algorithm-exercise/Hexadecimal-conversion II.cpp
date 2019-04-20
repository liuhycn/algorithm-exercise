//
//  5000   Hexadecimal-conversion II.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int converter1(char c)
{
    int ans = 0;
    if (c >= '0' && c <= '9')
    {
        ans =  c - '0';
    }
    else if (c >= 'A' && c <= 'F')
    {
        ans =  c - 55;
    }
    else if (c >= 'a' && c <= 'f')
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
    else if (a >= 10 && a <= 15)
    {
        ans = a + 55;
    }
    return ans;
}

int main()
{
    int a,b;
    char n[50] = {0};
    cout<<"welcome"<<endl;
    while(scanf("%d%s%d",&a,n,&b)!=EOF)
    {
        long int temp = 0;
        for(int i = 0; i < strlen(n); i++)
        {
            temp = temp * a;
            temp = temp + converter1(n[i]);
        }
        char ans[50];
        int size = 0;
        if (temp == 0)
        {
            size++;
            ans[0] = '0';
        }
        while(temp != 0)
        {
            ans[size++] = converter2(temp%b);
            temp = temp / b;
        }
        for(int i = size-1;i>=0;i--)
        {
            printf("%c",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
