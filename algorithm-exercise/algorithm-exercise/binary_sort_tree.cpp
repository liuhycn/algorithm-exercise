//
//  binary_sort_tree.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/11.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

struct node
{
    int val;
    node* left;
    node* right;
}tree[110];                             //树用静态数组来存储
int loc = 0;                                //静态数组中被使用的元素个数
node* creat()                           //申请未使用的节点
{
    tree[loc].left = NULL;
    tree[loc].right = NULL;
    return &tree[loc++];
}
void postOrder(node* root)                  //后序遍历
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->val);
    }
}
void inOrder(node* root)                    //中序遍历
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        printf("%d ",root->val);
        inOrder(root->right);
    }
}
void preOrder(node* root)                   //前序遍历
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ",root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}
node* insert(node* root, int x)
{
    if(root == NULL)
    {
        node* ans = creat();
        ans->val = x;
        return ans;
    }
    else if(x < root->val)
    {
        root->left = insert(root->left, x);
    }
    else if(x > root->val)
    {
        root->right = insert(root->right, x);
    }
    return root;
}
int main()
{
    cout<<"welcome"<<endl;
    int n;
    while(scanf("%d",&n) != EOF)
    {
        node* root = NULL;
        int x;
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&x);
            root = insert(root, x);
            
        }
        printf("前序遍历\n");
        preOrder(root);
        printf("中序遍历\n");
        inOrder(root);
        printf("后序遍历\n");
        postOrder(root);
    }
    
    return 0;
}
