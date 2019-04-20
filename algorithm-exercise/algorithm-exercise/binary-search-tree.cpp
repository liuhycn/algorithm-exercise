//
//  binary_search_tree.cpp
//  wangdao_exercise
//
//  Created by Hongyan Liu on 2019/4/17.
//  Copyright © 2019 Hongyan Liu. All rights reserved.
//
//特点：左子树上的所有节点都小于根节点，
//     右子树上的所有节点都大于根节点
//     左子树和右子树都满足以上规则
//查找的时间从O(n)->O(logn)
//中序遍历，递增序列


#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

struct node
{
    int val;
    node* left;
    node* right;
}tree[10000];
int loc = 0;
node* creat(int x)
{
    tree[loc].left = NULL;
    tree[loc].right = NULL;
    tree[loc].val = x;
    return &tree[loc++];
}
node* insert(node* root,int x)
{
    if(root == NULL)
    {
        return creat(x);
    }
    if(x < root->val)
    {
        root->left = insert(root->left,x);
    }
    else if (x >= root->val)
    {
        root->right = insert(root->right,x);
    }
    return root;
}
char first[100] = {0};
char second[100] = {0};
int size = 0;
char tmp[100] = {0};
void preOrder(node* root,char* str)
{
    if(root == NULL)
    {
        return;
    }
    str[size++] = root->val + '0';
    preOrder(root->left,str);
    //printf("%d",root->val);
    preOrder(root->right,str);
}
void inOrder(node* root,char* str)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left,str);
    str[size++] = root->val + '0';
    //printf("%d",root->val);
    inOrder(root->right,str);
}

int main()
{
    int n;
    printf("welcome\n");
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0)
        {
            break;
        }
        size = 0;
        loc = 0;
        memset(tmp, 0, sizeof(tmp));
        memset(first, 0, sizeof(first));
        memset(tree, 0, sizeof(tree));
        scanf("%s",tmp);
        node* root = NULL;
        for(int i = 0;i<strlen(tmp);i++)
        {
            root = insert(root, tmp[i]-'0');
        }
        preOrder(root, first);
        inOrder(root, first);
        //printf("%s\n",first);
        for(int i = 0;i<n;i++)
        {
            node* t = NULL;
            memset(tmp, 0, sizeof(tmp));
            memset(second, 0, sizeof(second));
            size = 0;
            scanf("%s",tmp);
            for(int i = 0;i<strlen(tmp);i++)
            {
                t = insert(t, tmp[i]-'0');
            }
            preOrder(t, second);
            inOrder(t, second);
            //printf("%s\n",second);
            if(strcmp(first,second) == 0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
