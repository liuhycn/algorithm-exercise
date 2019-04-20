#include<iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main()
{
	int n;
	while (1)
	{
		scanf_s("%d", &n);
		if (n == 0) break;
		int score[1001] = { 0 };
		int cnt[101] = { 0 };
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d", &score[i]);
			cnt[score[i]]++;
		}
		int request;
		scanf_s("%d", &request);
		printf("%d\n", cnt[request]);
	}
	return 0;
}