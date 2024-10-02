#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector< vector<int> > res;
vector<int> path;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
}TreeNode;

void backtrace(TreeNode *root, int tar)
{
    if (root == nullptr)
        return;

    path.push_back(root->val);
    tar -= root->val;

    if (tar == 0 && root->left == nullptr && root->right == nullptr)
        res.push_back(path);

    backtrace(root->left, tar);
    backtrace(root->right, tar);
    path.pop_back();
}

vector< vector<int> > pathSum(TreeNode *root, int targetSum)
{
    backtrace(root, targetSum);
    return res;
}



