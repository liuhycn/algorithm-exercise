#include<iostream>
#include<stack>
#include<stdlib.h>
#include<string.h>
using namespace std;




int main()
{
	char buf[1001] = { 0 };
	char ans[1001] = { 0 };
	
	stack<char>s;
	stack<char>index;
	while (scanf("%s", buf) != EOF)
	{
		//printf("%d", strlen(buf));
		for (int i = 0; i < strlen(buf); i++)
		{
			if (buf[i] == '(')
			{
				s.push(buf[i]);
				index.push(i);
			}
			else if (buf[i] == ')')
			{
				if (s.empty())
				{
					ans[i] = '?';
				}
				else
				{
					s.pop();
					ans[index.top()] = ' ';
					index.pop();
					ans[i] = ' ';
				}
			}
			else
			{
				ans[i] = ' ';
			}
		}
		while (!s.empty())
		{
			ans[index.top()] = '$';
			s.pop();
			index.pop();
		}
		printf("%s\n", ans);
	}
	return 0;
}