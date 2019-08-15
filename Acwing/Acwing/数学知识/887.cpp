#include <iostream>

using namespace std;

typedef long long LL;

int qmi(int a, int b, int p)
{
	if (b == 0) return 1;
	LL tmp = qmi(a, b >> 1, p);
	if (b % 2 == 1) return tmp * a % p * tmp % p;
	else return tmp * tmp % p;
}

int C(int a, int b, int p)
{
	if (a < b) return 0;
	LL res = 1;
	for (int i = a - b + 1; i <= a; i++)
		res = res * i % p;
	LL factb = 1;
	for (int i = 1; i <= b; i++)
		factb = factb * i % p;
	return (LL)res * qmi(factb, p - 2, p) % p;
}

int lucas(LL a, LL b, int p)
{
	if (a < p && b < p) return C(a, b, p);
	int tmp = lucas(a / p, b / p, p);
	return (LL)tmp * C(a % p, b % p, p) % p;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n ;i++)
	{
		LL a, b, p;
		scanf("%lld%lld%lld", &a, &b, &p);
		printf("%d\n", lucas(a, b, p));
	}
	return 0;
}