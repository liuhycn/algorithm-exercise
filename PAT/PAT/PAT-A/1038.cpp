#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str[10001];

bool cmp(string str1, string str2)
{
    string tmp1 = str1 + str2;
    string tmp2 = str2 + str1;
    return tmp1 < tmp2;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> str[i];
    sort(str, str + n, cmp);
    string ans = "";
    for (int i = 0; i < n; i++)
        ans += str[i];
    /***********************/
    while (ans.size() > 1 && ans[0] == '0') ans.erase(ans.begin());
    /***********************/
    cout << ans;
    return 0;
}
