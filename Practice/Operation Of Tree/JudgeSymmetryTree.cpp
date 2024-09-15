#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 判断二叉树是否为对称二叉树

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

bool judgement(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr || root1->val != root2->val)
        return false;
    return judgement(root1->left, root2->right) && judgement(root1->right, root2->left);
}

bool issymmetry(TreeNode *root)
{
    if(root==nullptr)
        return true;
    return judgement(root->left, root->right);
}



int main()
{
    
    return 0;
}
