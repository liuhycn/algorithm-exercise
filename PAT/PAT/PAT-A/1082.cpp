#include <iostream>
#include <string>

using namespace std;

string digit[10] = {
    "ling ",
    "yi ",
    "er ",
    "san ",
    "si ",
    "wu ",
    "liu ",
    "qi ",
    "ba ",
    "jiu "
};

int main()
{
    cout << endl;
    string nums;
    cin >> nums;
    int flag = 0;
    if (nums[0] == '-')
    {
        flag = 1;
        nums.erase(nums.begin());
    }
    while (nums.size() < 12) nums = '0' + nums;
    string res = "";
    for (int i = 0; i < 3; i++)
    {
        int cnt = 0;
        if (nums[0] != '0')
        {
            res += digit[nums[0] - '0'];
            res += "Qian ";
        }
        else
        {
            res += "ling ";
            cnt ++;
        }
        if (nums[1] != '0')
        {
            res += digit[nums[1] - '0'];
            res += "Bai ";
        }
        else
        {
            res += "ling ";
            cnt ++;
        }
        if (nums[2] != '0')
        {
            res += digit[nums[2] - '0'];
            res += "Shi ";
        }
        else
        {
            res += "ling ";
            cnt ++;
        }
        if (nums[3] != '0')
        {
            res += digit[nums[3] - '0'];
        }
        else
        {
            res += "ling ";
            cnt ++;
        }
        if (res.size() != 0)
        {
            if (i == 0 && cnt != 4)
            {
                while (res[res.size() - 5] == 'l' && res[res.size() - 4] == 'i' && res[res.size() - 3] == 'n' && res[res.size() - 2] == 'g' && res[res.size() - 1] == ' ') res.erase(res.end() - 5, res.end());
                res += "Yi ";
            }
            if (i == 1 && cnt != 4)
            {
                while (res[res.size() - 5] == 'l' && res[res.size() - 4] == 'i' && res[res.size() - 3] == 'n' && res[res.size() - 2] == 'g' && res[res.size() - 1] == ' ') res.erase(res.end() - 5, res.end());
                res += "Wan ";
            }
        }
        nums.erase(nums.begin(), nums.begin() + 4);
        if (cnt == 4) res.erase(res.begin(), res.begin() + 20);
    }
    
    if (res.size() == 0) res = "ling";
    while (res[0] == 'l' && res[1] == 'i' && res[2] == 'n' && res[3] == 'g' && res[4] == ' ') res.erase(res.begin(), res.begin() + 5);
    while (res[res.size() - 5] == 'l' && res[res.size() - 4] == 'i' && res[res.size() - 3] == 'n' && res[res.size() - 2] == 'g' && res[res.size() - 1] == ' ') res.erase(res.end() - 5, res.end());
    for (int i = 0; i < res.size(); i++)
    {
        while (res[i] == 'l' && i + 1 < res.size() && res[i + 1] == 'i' && i + 2 < res.size() && res[i + 2] == 'n'&& i + 3 < res.size() && res[i + 3] == 'g' && i + 4 < res.size() && res[i + 4] == ' ' && i + 5 < res.size() && res[i + 5] == 'l' && i + 6 < res.size() && res[i + 6] == 'i' && i + 7 < res.size() && res[i + 7] == 'n' && i + 8 < res.size() && res[i + 8] == 'g' && i + 9 < res.size() && res[i + 9] == ' ')
        {
            res.erase(res.begin() + i, res.begin() + i + 5);
        }
    }
    if (res[res.size() - 1] == ' ') res.erase(res.end() - 1);
    if (res.size() != 0 && flag == 1) res = "Fu " + res;
    cout << res;
    return 0;
}
