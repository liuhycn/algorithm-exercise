#include<iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main()
{
	int h;
	scanf_s("%d", &h);
	int blank_cnt;
	int star_cnt;
	int max_cnt = h + (h - 1) * 2;
	for (int i = 0; i < h; i++)
	{
		star_cnt = h + i * 2;
		blank_cnt = max_cnt - star_cnt;
		for (int j = 0; j < blank_cnt; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < star_cnt; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}