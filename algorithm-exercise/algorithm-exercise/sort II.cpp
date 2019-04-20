#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int x, int y)						//Custom comparison functions
{
	return x > y;
}

int main()
{
	int arr[10000] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);				//Overloading sort function
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}