#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

//  判断是否为平衡二叉树，树中每个结点左右子树高度差不超过一

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
    return max(height(root->left),height(root->right))+1;
}

bool isbalance(TreeNode *root)
{
    if(root==nullptr)
        return true;
    return abs(height(root->left) - height(root->right)) <= 1 && 
    isbalance(root->left) && isbalance(root->right);
}

int main()
{
    
    return 0;
}
