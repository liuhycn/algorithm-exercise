#include <iostream>

using namespace std;

const int N = 1000001;
int phi[N];

typedef long long LL;
int st[N];
int primes[N], primescnt;
int n;

LL getphi(int x)
{
    LL res = 0;
    phi[1] = 1;
    phi[2] = 2;
    for (int i = 2; i <= x; i++)
    {
        if (st[i] == 0) 
        {
            primes[primescnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= x / i; j++)
        {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            else
            {
                phi[i * primes[j]] = phi[i] * primes[j] * (primes[j] - 1) / primes[j];
            }
        }
    }
    for (int i = 1; i <= x; i++)
        res += phi[i];
    return res;
}

int main()
{
    scanf("%d", &n);
    printf("%lld", getphi(n));
}