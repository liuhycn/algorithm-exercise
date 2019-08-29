//
//  1057.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/27.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

const int N = 100001;

int s[N], tt;

bool empty()
{
    if (tt == 0) return true;
    else return false;
}

int pop()
{
    tt --;
    return s[tt];
}

void push(int x)
{
    s[tt ++] = x;
}

int getmid()
{
    if (tt % 2 == 1) return s[(tt + 1) / 2 - 1];
    else return s[tt / 2 - 1];
}

int main()
{
    cout << endl;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;
        if (op == "Push")
        {
            int x;
            scanf("%d", &x);
            push(x);
        }
        else if (op == "Pop")
        {
            if (empty()) printf("Invalid\n");
            else printf("%d\n", pop());
        }
        else if (op == "PeekMedian")
        {
            if (empty()) printf("Invalid\n");
            else printf("%d\n", getmid());
        }
    }
    return 0;
}
