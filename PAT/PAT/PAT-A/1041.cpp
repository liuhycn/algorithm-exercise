#include <iostream>
#include <vector>

using namespace std;

int visit[10001];
vector<int> buf;


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int nums;
        cin >> nums;
        buf.push_back(nums);
        visit[nums] ++;
    }
    int res = -1;
    for (auto nums : buf)
    {
        if (visit[nums] == 1)
        {
            res = nums;
            break;
        }
    }
    if (~res)
        cout << res;
    else
        cout << "None";
    return 0;
}
