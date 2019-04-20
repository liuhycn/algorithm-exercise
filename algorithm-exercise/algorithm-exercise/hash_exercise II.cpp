#include<iostream>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int cnt[1000001] = { 0 };

int main()
{
	int n, m;
	while (scanf_s("%d%d", &n, &m) != EOF)
	{
		int val;
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d", &val);
			if (val < 0) val = -1 * val + 500000;
			cnt[val]++;
		}

		for (int i = 500000; i >= 0; i--)
		{
			//cout << "1" << endl;
			if (cnt[i])
			{
				printf("%d ", i);
				m--;
				if (!m)
				{
					printf("\n");
					break;
				}
			}
		}
		if (m)
		{
			for (int i = 500001; i <= 1000000; i++)
			{
				if (cnt[i])
				{
					printf("%d ", -1 * (i - 500000));
					m--;
					if (!m)
					{
						printf("\n");
						break;
					}
				}
			}
		}
	}
	return 0;

}