#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 判断二叉树的结点的值等于左右子树值之和

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

int calculate(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    if(root->left==nullptr&&root->right==nullptr)
        return root->val;
    if(root->left==nullptr||root->right==nullptr)
        return root->left == nullptr ? calculate(root->right) : calculate(root->left);
    return calculate(root->left) + calculate(root->right);
}

bool isequal(TreeNode *root)
{
    if(root==nullptr)
        return true;
    if(root->val==root->left->val+root->right->val)
        return true;
    return root->val == calculate(root);
}



int main()
{
    
    return 0;
}
