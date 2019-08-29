#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int toint(string str)
{
    int res;
    sscanf(str.c_str(), "%d", &res);
    return res;
}


int main()
{
    string nums;
    cin >> nums;
    int flag = 0;
    if (nums[0] == '+') nums.erase(nums.begin());
    else
    {
        flag = 1;
        nums.erase(nums.begin());
    }
    int eindex = 0;
    while (eindex < nums.size() && nums[eindex] != 'E') eindex ++;
    int e = toint(nums.substr(eindex + 1, nums.size() - 1 - eindex));
    nums = nums.substr(0, eindex);
    if (e > 0)
    {
        if (e >= nums.size() - 2)
        {
            int loop = e - nums.size() + 2;
            nums.erase(nums.begin() + 1);
            for (int i = 0; i < loop; i++) nums += '0';
        }
        else
        {
            int pointindex = 1;
            for (int i = 0; i < e; i++)
            {
                swap(nums[pointindex], nums[pointindex + 1]);
                pointindex ++;
            }
        }
    }
    else if (e < 0)
    {
        e = e * -1;
        e --;
        nums.erase(nums.begin() + 1);
        string tmp = "0.";
        for (int i = 0; i < e; i++) tmp += '0';
        nums = tmp + nums;
    }
    if (flag == 1) nums = '-' + nums;
    cout << nums;
    return 0;
}
