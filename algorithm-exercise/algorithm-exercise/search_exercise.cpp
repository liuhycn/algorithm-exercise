#include<iostream>

#define _CRT_SECURE_NO_WARNINGS


using namespace std;

int buf[201] = { 0 };

int main()
{
	int n;
	while (scanf_s("%d", &n) != EOF)
	{
		int ans = -1;
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d", &buf[i]);
		}
		int x;
		scanf_s("%d", &x);
		for (int i = 0; i < n; i++)
		{
			if (buf[i] == x)
			{
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}