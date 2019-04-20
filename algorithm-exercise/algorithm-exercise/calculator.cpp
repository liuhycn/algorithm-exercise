#include<iostream>
#include<stack>

using namespace std;

int mat[6][6] =					//优先级矩阵，0代表不可以计算，1代表可以计算，2代表()相遇，
{
	1,1,0,0,0,1,
	1,1,0,0,0,1,
	1,1,1,1,0,1,
	1,1,1,1,0,1,
	0,0,0,0,0,2,
	1,1,1,1,1,1
};

int optoNum(char a)
{
	switch (a)
	{
		case '+': return 0; break;
		case '-': return 1; break;
		case '*': return 2; break;
		case '/': return 3; break;
		case '(': return 4; break;
		case ')': return 5; break;
	}
}
double calculate(double num1, double num2, char op)
{
	if (op == '+')
	{
		return num1 + num2;
	}
	else if (op == '-')
	{
		return num1 - num2;
	}
	else if (op == '*')
	{
		return num1 * num2;
	}
	else if (op == '/')
	{
		return num1 / num2;
	}
}
int main()
{
	char str[200001] = { 0 };
	while (scanf("%s", str) != EOF)
	{
		stack<char>operators;
		stack<double>nums;
		int numflag = 0;
		int temp = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == ' '|| str[i] == '"')
			{
				continue;
			}
			else if (str[i] >= '0' && str[i] <= '9')					//遇见数字
			{
				temp = temp * 10 + (str[i] - '0');
				numflag = 1;
				//cout << temp << endl;
			}
			else												//遇见操作符
			{
				if (numflag == 1)
				{
					numflag = 0;
					nums.push(temp);
					//cout << temp << endl;
					temp = 0;
				}
				while (1)
				{
					if (operators.empty())
					{
						operators.push(str[i]);
						//cout << str[i] << endl;
						break;
					}
					else
					{
						int flag = mat[optoNum(operators.top())][optoNum(str[i])];
						if (flag == 0)								//不可计算
						{
							operators.push(str[i]);
							break;
						}
						else if (flag == 1)							//可以计算
						{
							double num2 = nums.top();
							nums.pop();
							double num1 = nums.top();
							nums.pop();
							char op = operators.top();
							operators.pop();
							int ans = calculate(num1, num2, op);
							nums.push(ans);
						}
						else										//()相遇
						{
							operators.pop();
							break;
						}
					}
				}
			}
		}
		//cout << temp << endl;
		if (temp != 0 || str[strlen(str) - 1] == '0')
		{
			nums.push(temp);
		}

		while (!operators.empty())
		{
			double num2 = nums.top();
			nums.pop();
			double num1 = nums.top();
			nums.pop();
			char op = operators.top();
			operators.pop();
			int ans = calculate(num1, num2, op);
			nums.push(ans);
		}
		cout << nums.top() << endl;
		//printf(".3lf\n", nums.top());
		
	}
	return 0;
}