//
//  831.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/7.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

/*
 “ababa”
 
 “aba”
*/



#include "Header.h"

char s[100001];
char p[10001];
int n, m;
int ne[10001];

int main()
{
    pp();
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
        scanf("%c", &p[i]);
    scanf("%d", &m);
    getchar();
    for (int i = 1; i <= m; i++)
        scanf("%c", &s[i]);
    
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[j + 1] != p[i]) j = ne[j];
        if (p[j + 1] == p[i]) j++;
        ne[i] = j;
    }
    
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }
    return 0;
}

