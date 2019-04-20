#include<iostream>
#include<algorithm>
#define _CRT_SECURE_NO_WORNINGS

using namespace std;

int buf[101] = { 0 };

int main()
{
	int n;
	while (scanf_s("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d", &buf[i]);
		}
		int x;
		scanf_s("%d", &x);
		sort(buf, buf + n);
		int l = 0;
		int r = n - 1;
		int flag = 0;
		int mid;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (buf[mid] == x)
			{
				flag = 1;
				break;
			}
			else if (x > buf[mid])
			{
				l = mid + 1;
			}
			else if (x < buf[mid])
			{
				r = mid - 1;
			}
		}
		if (buf[mid] != x)printf("-1\n");
		else printf("%d\n", mid);
	}
	return 0;
}