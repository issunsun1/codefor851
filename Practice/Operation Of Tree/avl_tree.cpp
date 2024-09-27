#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef int datatype;

// 平衡二叉树的调整从最小不平衡子树开始

typedef struct TreeNode
{
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(-1), left(nullptr), right(nullptr) {};
} TreeNode;

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

// LL r1为最小不平衡子树的根结点
TreeNode *ll_rotation(TreeNode *r1)
{
    TreeNode *r2 = r1->left;

    r1->left = r2->right;
    r2->right = r1;

    r2->height = height(r2);
    r1->height = height(r1);

    return r2;
}

// RR旋转
TreeNode *rr_rotation(TreeNode *r1)
{
    TreeNode *r2 = r1->right;
    r1->right = r2->left;
    r2->left = r1;

    r2->height = height(r2);
    r1->height = height(r1);
    return r2;
}

// LR 先左旋再右旋
TreeNode *lr_rotation(TreeNode *r1)
{
    r1->left = ll_rotation(r1->left);
    return rr_rotation(r1);
}

// RL 先右旋再左旋
TreeNode *rl_rotation(TreeNode *r1)
{
    r1->right = rr_rotation(r1->right);
    return ll_rotation(r1);
}


int main()
{

    return 0;
}
