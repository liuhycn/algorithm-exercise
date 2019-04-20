//
//  build_Huffman_tree.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/10.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//
// new返回结构体指针

#include <iostream>
#include <queue>

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

struct cmp                                          //自制greater
{
  bool operator ()(const treeNode* a, const treeNode* b)const
    {
        return a->val > b->val;
    }
};

void dfs(treeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        dfs(root->left);
        printf("%d ",root->val);
        dfs(root->right);
    }
    
}

int main()
{
    priority_queue<treeNode*,vector<treeNode*>,cmp> heap;
    int n;
    //cout<<"welcome"<<endl;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        heap.push(new treeNode(x));
    }
    cout<<heap.size()<<endl;
    int ans = 0;
    while(heap.size() > 1)
    {
        treeNode* n1 = heap.top();                      //取两个权值最小的节点
        heap.pop();
        treeNode* n2 = heap.top();
        heap.pop();
        int plus = n1->val + n2->val;
        ans = ans + plus;                               //求解WLP
        treeNode* temp = new treeNode(plus);            //新节点，其权值等于两节点之和
        temp->left = n1;
        temp->right = n2;
        heap.push(temp);                                //入堆
    }
    
    treeNode* root = heap.top();

    dfs(root);
    
    return 0;
}

