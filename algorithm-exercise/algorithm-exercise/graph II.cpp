#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
char buf[81][81] = { 0 };
int main()
{
	int n;
	char c1, c2;
	bool first = true;
	while (scanf("%d %c %c", &n, &c1, &c2) != EOF)
	{
		if (!first) printf("\n");
		first = false;
		char firstchar;
		char secondchar;
		if ((n - 1) % 2 == 0)
		{
			firstchar = c1;
			secondchar = c2;
		}
		else
		{
			firstchar = c2;
			secondchar = c1;
		}
		int loop = (n + 1) / 2;
		for (int i = 0; i < loop; i++)
		{
			char thischar;
			if (i % 2 == 0)thischar = secondchar;
			else thischar = firstchar;
			int loop2 = n - i * 2;
			//cout << loop2 << endl;
			int k = i;
			for (int j = 0; j < loop2; j++)				//左竖线
			{
				buf[k][i] = thischar;
				//cout << k << " " << i << endl;
				k++;
			}
			k = i;
			for (int j = 0; j < loop2; j++)				//下横线
			{
				buf[n - 1 - i][k] = thischar;
				k++;
			}
			k = i;
			for (int j = 0; j < loop2; j++)				//右竖线
			{
				buf[k][n - 1 - i] = thischar;
				k++;
			}
			k = i;
			for (int j = 0; j < loop2; j++)				//上横线
			{
				buf[i][k] = thischar;
				k++;
			}
		}
		if (n != 1)
		{
			buf[0][0] = ' ';
			buf[0][n - 1] = ' ';
			buf[n - 1][0] = ' ';
			buf[n - 1][n - 1] = ' ';
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%c ", buf[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}