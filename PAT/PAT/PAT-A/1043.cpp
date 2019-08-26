//
//  1043.cpp
//  PAT
//
//  Created by Hongyan Liu on 2019/8/26.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

struct treeNode
{
    int val;
    treeNode* left;
    treeNode* right;
    treeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

unordered_map<int, vector<int>> dict;
vector<int> inorder;
vector<int> preorder;
vector<int> postorder;
treeNode* dfs(int pl, int pr, int il, int ir, int tag)
{
    if (pl > pr || il > ir) return NULL;
    treeNode *tmp = new treeNode(0);
    tmp->val = preorder[pl];
    int headindex;
    if (tag == 0)
    {
        headindex = dict[tmp->val][0];
        dict[tmp->val].erase(dict[tmp->val].begin());
    }
    else
    {
        headindex = dict[tmp->val][dict[tmp->val].size() - 1];
        dict[tmp->val].pop_back();
    }
    tmp->left = dfs(pl + 1, pl + headindex - il, il, headindex - 1, tag);
    tmp->right = dfs(pl + headindex - il + 1, pr, headindex + 1, ir, tag);
    return tmp;
}


void dfs(treeNode *root)
{
    if (root == NULL) return;
    dfs(root->left);
    dfs(root->right);
    postorder.push_back(root->val);
}

bool cmp(int a, int b)
{
    return a > b;
}

bool isbst(int l, int r, int tag)
{
    if (l == r) return true;
    if (tag == 0)
    {
        int i = l;
        while (i + 1 <= r && preorder[i + 1] < preorder[l])
        {
            i ++;
        }
        int j = i;
        while (j + 1 <= r && preorder[j + 1] >= preorder[l])
        {
            j ++;
        }
        if (j == r) return isbst(l + 1, i, tag) && isbst(i + 1, r, tag);
        else return false;
    }
    else
    {
        int i = l;
        while (i + 1 <= r && preorder[i + 1] >= preorder[l])
        {
            i ++;
        }
        int j = i;
        while (j + 1 <= r && preorder[j + 1] < preorder[l])
        {
            j ++;
        }
        if (j == r) return isbst(l + 1, i, tag) && isbst(i + 1, r, tag);
        else return false;
    }
}


int main()
{
    cout << endl;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        preorder.push_back(a);
        inorder.push_back(a);
    }
    int tag = 0;
    if (preorder[1] >= preorder[0]) tag = 1;
    if (isbst(0, n - 1, tag) == false)
    {
        cout << "NO";
        return 0;
    }
    
    if (tag == 0) sort(inorder.begin(), inorder.end());
    else sort(inorder.begin(), inorder.end(), cmp);
    for (int i = 0; i < inorder.size(); i++)
    {
        if (dict.find(inorder[i]) == dict.end()) dict[inorder[i]] = vector<int>(1, i);
        else dict[inorder[i]].push_back(i);
    }
    treeNode* root = dfs(0, n - 1, 0, n - 1, tag);
    dfs(root);
    cout << "YES" << endl;
    for (int i = 0; i < postorder.size(); i++)
        if (i == 0) cout << postorder[i];
        else cout << ' ' << postorder[i];
    return 0;
}
