#include <iostream>

using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);
        int x, y;
        int tmp = exgcd(a, m, x, y);
        if (b % tmp == 0)
        {
            printf("%lld\n", (long long)b / tmp * x % m);
        }
        else 
            puts("impossible");
    }
}