//
//  1720.cpp
//  HDOJ
//
//  Created by Hongyan Liu on 2019/4/27.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int convertor(char x)
{
    int ans;
    if(x >= '0' && x <= '9')
    {
        ans = x - '0';
    }
    else if (x >='a' && x<='f')
    {
        ans = x - 'a' + 10;
    }
    else if (x >='A' && x<='F')
    {
        ans = x - 'A' + 10;
    }
    return ans;
}

long long int conver(char* str)
{
    long long int ans = 0;
    int length = strlen(str);
    for(int i = 0;i<length;i++)
    {
        ans = ans * 16;
        ans = ans + convertor(str[i]);
    }
    return ans;
}

int main()
{
    char a[20];
    char b[20];
    //pp();
    while (scanf("%s%s",a,b)!=EOF)
    {
        getchar();
        long long int tempa = conver(a);
        long long int tempb = conver(b);
        printf("%lld\n",tempa + tempb);
    }
    return 0;
}
