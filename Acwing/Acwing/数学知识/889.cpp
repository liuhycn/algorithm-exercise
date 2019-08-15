#include <iostream>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int qmi(int a, int b)
{
    if (b == 0) return 1;
    int tmp = qmi(a, b >> 1);
    if (b & 1) return (LL)tmp * tmp % mod * a % mod;
    else return (LL)tmp * tmp % mod;
}

int main()
{
    int n;
    scanf("%d", &n);
    int res = 1;
    for (int i = 1; i <= (n << 1); i++)
    {
        res = (LL)res * i % mod;
    }
    int ans = res;
    res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = (LL)res * i % mod;
    }
    res = qmi(res, mod - 2);
    ans = (LL)ans * res % mod * res % mod * qmi(n + 1, mod - 2) % mod;
    printf("%d\n", ans);
    return 0;
}