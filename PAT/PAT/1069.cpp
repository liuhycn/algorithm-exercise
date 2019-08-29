#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int lastans;

int toint(string str)
{
    int a;
    sscanf(str.c_str() ,"%d", &a);
    return a;
}

string tostring(int x)
{
    stringstream ss;
    ss << x;
    return ss.str();
}

bool cmp(char a, char b)
{
    return  a > b;
}

int main()
{
    string nums;
    cin >> nums;
    int cnt = 4 - nums.size();
    string aa = "";
    for (int i = 0; i < cnt; i++) aa += '0';
    nums = aa + nums;
    if (nums[0] == nums[1] && nums[1] == nums[2] && nums[2] == nums[3])
    {
        printf("%s - %s = 0000", nums.c_str(), nums.c_str());
        return 0;
    }
    if (nums == "6174")
    {
        printf("7641 - 1467 = 6174\n");
        return 0;
    }
    lastans = toint(nums);
    while (1)
    {
        int intnums = lastans;
        string strnums = tostring(intnums);
        
        string strup = strnums;
        string strdown = strnums;
        
        sort(strup.begin(), strup.end(), cmp);
        sort(strdown.begin(), strdown.end());
        
        while (strup.size() < 4) strup += '0';
        
        int intup = toint(strup);
        int intdown = toint(strdown);
        
        int thisans = intup - intdown;
        
        if (thisans == lastans) break;
        else
        {
            printf("%04d - %04d = %04d\n", intup, intdown, thisans);
            lastans = thisans;
        }
        
        
    }
    return 0;
}
