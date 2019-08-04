//
//  1074.cpp
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
};

vector<ListNode>buf;
map<int, int> mymap;
vector<ListNode>list;

int main()
{
    pp();
    int firstaddr, n, k;
    scanf("%d%d%d", &firstaddr, &n, &k);
    for (int i = 0; i < n; i++)
    {
        ListNode tmp;
        scanf("%d%d%d", &tmp.addr, &tmp.val, &tmp.next);
        buf.push_back(tmp);
        mymap[tmp.addr] = i;
    }
    for (int i = 0; i < n; i++)
    {
        list.push_back(buf[mymap[firstaddr]]);
        firstaddr = list[i].next;
        //************************//
        if  (firstaddr == -1) break;
        //************************//
    }
    n = list.size();
    int l = 0;
    int loop = n / k;
    for (int i = 0; i < loop; i++)
    {
        reverse(list.begin() + l, list.begin() + l + k);
        l += k;
    }
    for (int i = 0; i < n - 1; i++)
    {
        list[i].next = list[i + 1].addr;
    }
    list[n - 1].next = -1;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            printf("%05d %d -1", list[i].addr, list[i].val);
        else
            printf("%05d %d %05d\n", list[i].addr, list[i].val, list[i].next);
    }
    return 0;
}
