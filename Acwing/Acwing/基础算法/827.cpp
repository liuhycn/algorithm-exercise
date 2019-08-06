//
//  827.cpp
//  Acwing
//
//  Created by Hongyan Liu on 2019/8/6.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

int l[100001];
int r[100001];
int e[100001];
int idx;

void init()
{
    l[0] = -1;
    r[0] = 1;
    l[1] = 0;
    r[1] = -1;
    idx = 2;
}


// del index == k
void del(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}


void display()
{
    for (int i = r[0]; i != 1; i = r[i])
    {
        printf("%d ", e[i]);
    }
    printf("\n");
}

void insert(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx ++;
}

int main()
{
    int m;
    pp();
    scanf("%d", &m);
    getchar();
    init();
    for (int i = 0; i < m; i++)
    {
        char flag;
        scanf("%c", &flag);
        if (flag == 'L')
        {
            int x;
            scanf("%d", &x);
            insert(0, x);
        }
        else if (flag == 'R')
        {
            int x;
            scanf("%d", &x);
            insert(l[1], x);
        }
        else if (flag == 'D')
        {
            int x;
            scanf("%d", &x);
            del(x + 1);
        }
        else
        {
            char c;
            int k, x;
            scanf("%c%d%d", &c, &k, &x);
            if (c == 'L')
            {
                insert(l[k + 1], x);
            }
            else
            {
                insert(k + 1, x);
            }
        }
        getchar();
    }
    display();
    return 0;
}

/*
 R 7
 D 1
 L 3
 IL 2 10
 D 3
 IL 2 7
 L 8
 R 9
 IL 4 7
 IR 2 2
*/
