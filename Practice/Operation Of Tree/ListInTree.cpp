// 判断二叉树中是否存在一条向下的路径与链表中的节点对应相等
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode *next;
} ListNode;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

bool dfs(ListNode *head, TreeNode *root)
{
    if(head==nullptr)
        return true;
    if(root==nullptr)
        return false;
    if(head->val!=root->val)
        return false;
    return dfs(head->next, root->left) || dfs(head->next, root->right);
}

bool ispath(ListNode *head,TreeNode *root)
{
    if(head==nullptr)
        return true;
    if(root==nullptr)
        return false;
    return dfs(head,root)||dfs(head, root->left) || dfs(head, root->right);
}

int main()
{
    
    return 0;
}
