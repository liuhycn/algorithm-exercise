#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

struct bigint
{
    int digit[100001];
    int size;
    void init()
    {
        size = 0;
        memset(digit, 0, sizeof digit);
    }
    void set(int n)
    {
        while (n != 0)
        {
            digit[size++] = n % 10;
            n /= 10;
        }
    }
    void display()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            printf("%01d", digit[i]);
        }
        printf("\n");
    }
};

bigint mul(bigint a, int b)
{
    bigint res;
    res.init();
    int c = 0;
    for (int i = 0; i < a.size; i++)
    {
        int tmp = (LL)a.digit[i] * b + c;
        res.digit[res.size++] = tmp % 10;
        c = tmp / 10;
    }
    while (c != 0)
    {
        res.digit[res.size++] = c % 10;
        c /= 10;
    }
    return res;
}

int getcnt(int a, int p)
{
    int sum = 0;
    while (a >= p)
    {
        sum += a / p;
        a /= p;
    }
    return sum;
}
const int N = 5000;
int primes[N];
int primescnt;
int st[N];

void setprimes()
{
    for (int i = 2; i <= N; i++)
    {
        if (!st[i]) primes[primescnt++] = i;
        for (int j = 0; primes[j] <= N / i; j++)
        {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	bigint ans;
	ans.init();
	ans.set(1);
	setprimes();
	for (int i = 0; i < primescnt; i++)
	{
	    int s = 0;
	    s += getcnt(a, primes[i]);
	    s -= getcnt(a - b, primes[i]);
	    s -= getcnt(b, primes[i]);
	    for (int j = 0; j < s; j++)
	        ans = mul(ans, primes[i]);
	}
	ans.display();
	return 0;
}