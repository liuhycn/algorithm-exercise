//
//  1081.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/29.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

struct fenshu
{
    LL fenzi;
    LL fenmu;
};

LL gcd(LL a, LL b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}


fenshu add(fenshu a, fenshu b)
{
    LL tmp = a.fenmu * b.fenmu / gcd(a.fenmu, b.fenmu);
    LL res = (tmp / a.fenmu) * a.fenzi + (tmp / b.fenmu) * b.fenzi;
    return {res, tmp};
}

int n;

int main()
{
    cout << endl;
    scanf("%d", &n);
    fenshu ans = {0, 1};
    for (int i = 0; i < n; i++)
    {
        LL a, b;
        scanf("%lld/%lld", &a, &b);
        fenshu tmp = {a, b};
        ans = add(ans, tmp);
        LL g = gcd(ans.fenzi, ans.fenmu);
        ans.fenzi = ans.fenzi / g;
        ans.fenmu = ans.fenmu / g;
    }
    int flag = 0;
    if (ans.fenzi < 0)
    {
        flag = 1;
        ans.fenzi = ans.fenzi * -1;
    }
    if (ans.fenmu == 1)
    {
        if (flag == 1) printf("-");
        printf("%lld", ans.fenzi);
        return 0;
    }
    if (ans.fenzi == 0) printf("0");
    else
    {
        if (flag == 1) printf("-");
        if (ans.fenzi == ans.fenmu) printf("1");
        else if (ans.fenzi < ans.fenmu) printf("%lld/%lld", ans.fenzi, ans.fenmu);
        else if (ans.fenmu < ans.fenzi) printf("%lld %lld/%lld", ans.fenzi / ans.fenmu, ans.fenzi % ans.fenmu, ans.fenmu);
    }
    return 0;
}
