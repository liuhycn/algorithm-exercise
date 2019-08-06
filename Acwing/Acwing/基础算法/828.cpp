//
//  828.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/6.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int stk[100001];
int tt;

void init()
{
    tt = 0;
}

bool empty()
{
    if (tt == 0 && stk[0] == 0)
        return true;
    else
        return false;
}

void push(int x)
{
    stk[tt] = x;
    tt++;
}

void pop()
{
    tt--;
    stk[tt] = 0;
}

int top()
{
    return stk[tt - 1];
}

int main()
{
    int m;
    pp();
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int x;
            scanf("%d", &x);
            push(x);
        }
        else if (op == "query")
        {
            printf("%d\n", top());
        }
        else if (op == "pop")
        {
            pop();
        }
        else
        {
            if (empty() == true)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
