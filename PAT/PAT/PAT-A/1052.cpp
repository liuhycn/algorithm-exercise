//
//  1052.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/4.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

struct ListNode
{
    int addr;
    int val;
    int next;
    bool operator < (const ListNode& b)const
    {
        return val < b.val;
    }
};

vector<ListNode> buf;
vector<ListNode> list;
map<int, int> mymap;

int main()
{
    pp();
    int head, n;
    scanf("%d%d", &n, &head);
    for (int i = 0; i < n; i++)
    {
        ListNode tmp;
        scanf("%d%d%d", &tmp.addr, &tmp.val, &tmp.next);
        buf.push_back(tmp);
        mymap[tmp.addr] = i;
    }
    while (head != -1)
    {
        list.push_back(buf[mymap[head]]);
        head = list[list.size() - 1].next;
        if (list.size() == n) break;
    }
    if (list.size() == n && head != -1)
    {
        printf("0 -1");
        return 0;
    }
    n = list.size();
    sort(list.begin(), list.end());
    for (int i = 0; i < n - 1; i++)
    {
        list[i].next = list[i + 1].addr;
    }
    printf("%d %05d", n, list[0].addr);
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            printf("\n%05d %d -1", list[i].addr, list[i].val);
        else
            printf("\n%05d %d %05d", list[i].addr, list[i].val, list[i].next);
    }
    return 0;
}
