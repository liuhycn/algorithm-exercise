//
//  829.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/6.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int que[100001];
int idx;
int front;

void init()
{
    idx = 0;
    front = 0;
}

void pop()
{
    que[front] = 0;
    front ++;
}

bool empty()
{
    return que[front] == 0;
}

void push(int x)
{
    que[idx] = x;
    idx ++;
}

int query()
{
    return que[front];
}

int main()
{
    int m;
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
        else if (op == "pop")
        {
            pop();
        }
        else if (op == "empty")
        {
            if (empty())
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            printf("%d\n", query());
        }
    }
    return 0;
}
