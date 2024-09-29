#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;

    if (!root)
        return ans;

    while (!s.empty() || root)
    {
        while (root)
        {
            ans.push_back(root->val);
            s.push(root);
            root = root->left;
        }

        root = s.top();
        s.pop();
        root = root->right;
    }

    return ans;
}

vector<int> preorder_no_recursion(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> t;

    if (!root)
        return res;

    t.push(root);

    while(!t.empty())
    {
        TreeNode *temp = t.top();
        t.pop();
        res.push_back(temp->val);

        if(temp->right)
            t.push(temp->right);
        if(temp->left)
            t.push(temp->left);
    }

    return res;
}


void preorderwithrecursion(TreeNode *root,vector<int> a)
{
    if(!root)
        return;
    a.push_back(root->val);
    preorderwithrecursion(root->left,a);
    preorderwithrecursion(root->right,a);
}
