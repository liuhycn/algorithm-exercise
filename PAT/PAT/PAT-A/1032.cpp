//
//  1032.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/4.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include "Header.h"

struct ListNode
{
    int addr;
    char val;
    int next;
};

vector<ListNode> list1;
vector<ListNode> list2;
map<int ,int> mymap;
vector<ListNode> buf;
int visit[100000];

int main()
{
    pp();
    int head1, head2, n;
    int flag = 0;
    scanf("%d%d%d", &head1, &head2, &n);
    for (int i = 0; i < n; i++)
    {
        ListNode tmp;
        scanf("%d %c %d", &tmp.addr, &tmp.val, &tmp.next);
        buf.push_back(tmp);
        mymap[tmp.addr] = i;
    }
    while (head1 != -1)
    {
        visit[mymap[head1]] = 1;
        list1.push_back(buf[mymap[head1]]);
        head1 = list1[list1.size() - 1].next;
        
    }
    while (head2 != -1)
    {
        list2.push_back(buf[mymap[head2]]);
        if (visit[mymap[head2]] == 1)
        {
            flag = 1;
            break;
        }
        head2 = list2[list2.size() - 1].next;
    }
    if (flag == 0)
        printf("-1");
    else
        printf("%05d", head2);
    return 0;
}
