#include <iostream>
#include <map>
#include <math.h>

using namespace std;

const int mod = 1e9 + 7;
int n;
map<int, int> primes;

void fun(int x)
{
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0)
            {
                x /= i;
                s ++;
            }
            primes[i] += s;
        }
    }
    if (x > 1) primes[x] ++;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        fun(a);
    }
    long long int ans = 1;
    for (auto prime : primes)
    {
        long long int sum = 1;
        for (int i = 0; i < prime.second; i++)
        {
            sum = (sum * prime.first + 1) % mod;
        } 
        ans = (ans * sum) % mod;
    }
    printf("%lld\n", ans);
}