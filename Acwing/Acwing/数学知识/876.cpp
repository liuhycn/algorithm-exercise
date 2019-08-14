#include <iostream>

using namespace std;

long long int fun(int a, int b, int p)
{
    if (b == 0) return 1;
    long long int tmp = fun(a, b >> 1, p);
    if (b % 2 == 1)
    {
        return (((tmp * tmp) % p) * a) % p;
    }
    else
    {
        return (tmp * tmp) % p;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, p;
        scanf("%d%d", &a, &p);
        if (a % p == 0) puts("impossible");
        else
            printf("%lld\n", fun(a, p - 2, p));
    }
    return 0;
}