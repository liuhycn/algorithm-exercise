//
//  1078.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/29.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> table;

bool isprime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}

int getnextprime(int x)
{
    for (int i = x + 1; ;i ++)
    {
        if (isprime(i)) return i;
    }
}


int size, n;

int insert(int key)
{
    int index = key % size;
    if (table[index] == -1)
    {
        table[index] = key;
        return index;
    }
    else
    {
        if (table[index + 1] == -1)
        {
            table[index + 1] = key;
            return index + 1;
        }
        else return -1;
    }
}

int main()
{
    cout << endl;
    scanf("%d%d", &size, &n);
    if (!isprime(size)) size = getnextprime(size);
    table = vector<int>(size, -1);
    for (int i = 0; i < n; i ++)
    {
        int a;
        scanf("%d", &a);
        int res = insert(a);
        if (res == -1) printf("-");
        else printf("%d", res);
        if (i != n - 1) printf(" ");
    }
    return 0;
}
