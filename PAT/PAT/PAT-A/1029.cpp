#include <iostream>
#include <vector>

using namespace std;

const int N = 200001;

int nums1[N], nums2[N];

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums1[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &nums2[i]);
    }
    int i = 0;
    int j = 0;
    int index = -1;
    int tar = n + m - 1 >> 1;
    int res;
    int flag = 0;
    while (i < n && j < m)
    {
        if (nums1[i] < nums2[j])
        {
            index ++;
            if (index == tar) 
            {
                flag = 1;
                res = nums1[i];
                break;
            }
            i ++;
        }
        else
        {
            index ++;
            if (index == tar)
            {
                flag = 1;
                res = nums2[j];
                break;
            }
            j ++;
        }
    }
    if (flag == 1) 
    {
        printf("%d", res);
        return 0;
    }
    while (i > 0) 
    {
        index ++;
        if (index == tar) 
        {
            res = nums1[i];
            break;
        }
        i ++;
    }
    while (j > 0)
    {
        index ++;
        if (index == tar)
        {
            res = nums2[j];
            break;
        }
        j ++;
    }
    printf("%d", res);
    return 0;
}