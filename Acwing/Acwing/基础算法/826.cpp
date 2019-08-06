//
//  826.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/5.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int idx = 0;
int val[100001];
int ne[100001];
int head = -1;

void add(int x, int k)
{
    val[idx] = x;
    ne[idx] = ne[k - 1];
    ne[k - 1] = idx;
    idx ++;
}

void addhead(int x)
{
    val[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}

void del(int k)
{
    ne[k - 1] = ne[ne[k - 1]];
}

int main()
{
    pp();
    int m;
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++)
    {
        char flag;
        scanf("%c", &flag);
        if (flag == 'H')
        {
            int x;
            scanf("%d", &x);
            addhead(x);
        }
        else if (flag == 'D')
        {
            int k;
            scanf("%d", &k);
            if (k == 0)
                head = ne[head];
            else
                del(k);
        }
        else
        {
            int k, x;
            scanf("%d%d", &k, &x);
            add(x, k);
        }
        getchar();
    }
    for (int i = head; i != -1; i = ne[i])
        printf("%d ", val[i]);
    return 0;
}
