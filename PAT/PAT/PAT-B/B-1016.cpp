//
//  B-1016.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/5/5.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int main()
{
    char a[11];
    char da[2];
    char b[11];
    char db[2];
    scanf("%s%s%s%s",a,da,b,db);
    //printf("%s %s %s %s\n",a,da,b,db);
    long long int tempa = 0;
    long long int tempb = 0;
    int length = strlen(a);
    for (int i = 0; i<length; i++)
    {
        if(a[i] == da[0])
        {
            tempa = tempa * 10 + (da[0] - '0');
        }
    }
    length = strlen(b);
    for (int i = 0; i<length; i++)
    {
        if(b[i] == db[0])
        {
            tempb = tempb * 10 + (db[0] - '0');
        }
    }
    printf("%lld\n",tempa + tempb);
    return 0;
}
