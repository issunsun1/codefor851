#include <iostream>
#include <algorithm>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

int height(TreeNode *root)
{
    if(root==nullptr)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(TreeNode *root)
{
    if(root==nullptr)
        return true;
    return abs(height(root->left) - height(root->right) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    return 0;
}