//
//  1052.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/27.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <math.h>
#include <set>

using namespace std;

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
    int head, n;
    scanf("%d%d", &n, &head);
    for (int i = 0; i < n; i++)
    {
        ListNode tmp;
        scanf("%d%d%d", &tmp.addr, &tmp.val, &tmp.next);
        buf.push_back(tmp);
        mymap[tmp.addr] = i;
    }
    int flag = 0;
    while (head != -1)
    {
        if (mymap.find(head) != mymap.end())
        {
            ListNode tmp = buf[mymap[head]];
            list.push_back(tmp);
            head = tmp.next;
        }
        else
        {
            flag = 1;
            break;
        }
        
    }
    if (flag == 1 || list.size() == 0)
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
