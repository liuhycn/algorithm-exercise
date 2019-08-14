#include <iostream>

using namespace std;

int n;

bool isprime(int x)
{
    if (x < 2) return false;
	for (int i = 2; i <= x/i; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if (isprime(a))
			puts("Yes");
		else
			puts("No");
	}
	
	return 0;
}