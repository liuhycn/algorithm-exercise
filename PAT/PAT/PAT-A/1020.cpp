#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct treeNode
{
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

unordered_map<int, int> dict;

const int N = 31;

int porder[N], inorder[N];

treeNode *dfs(int pl, int pr, int il, int ir)
{
    if (pl > pr) return NULL;
    treeNode *res = new treeNode(porder[pr]);
    int lenleft = dict[porder[pr]] - il;
    res->left = dfs(pl, pl + lenleft - 1, il, dict[porder[pr]] - 1);
    res->right = dfs(pl + lenleft, pr - 1, dict[porder[pr]] + 1, ir);
    return res;
}

queue<treeNode*> Q;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &porder[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inorder[i]);
        dict[inorder[i]] = i;
    }
    treeNode *root = dfs(0, n - 1, 0, n - 1);
    Q.push(root);
    int cnt = 0;
    while (Q.size())
    {
        treeNode *cur = Q.front();
        Q.pop();
        cnt ++;
        if (cnt == n)
            printf("%d", cur->val);
        else
            printf("%d ", cur->val);
        if (cur->left) Q.push(cur->left);
        if (cur->right) Q.push(cur->right);
    }
    return 0;
}
