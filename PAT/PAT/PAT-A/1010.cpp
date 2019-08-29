#include <iostream>
#include <string>

using namespace std;

typedef long long LL;

int chartoInt(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    return 0;
}

LL toDec(string nums, LL ra)
{
    int len = nums.size();
    LL r = 1;
    LL res = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        res += chartoInt(nums[i]) * r;
        r *= ra;
    }
    return res;
}

bool find(string nums, LL tar, LL &res)
{
    LL l = 2;
    LL r = tar;
    while (l < r)
    {
        LL mid = l + r >> 1;
        if (toDec(nums, mid) >= tar || toDec(nums, mid) < 0)
            r = mid;
        else l = mid + 1;
    }
    if (toDec(nums, l) == tar)
    {
        res = l;
        return true;
    }
    return false;
}

int main()
{
    cout << endl;
    string nums1, nums2;
    LL tag, ra;
    cin >> nums1 >> nums2 >> tag >> ra;
    LL tar;
    LL res;
    string tmp;
    if (tag == 1)
    {
        tar = toDec(nums1, ra);
        tmp = nums2;
    }
    if (tag == 2)
    {
        tar = toDec(nums2, ra);
        tmp = nums1;
    }
    if (find(tmp, tar, res)) printf("%lld", res);
    else printf("Impossible");
    return 0;
}
