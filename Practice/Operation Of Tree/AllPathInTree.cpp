#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 二叉树从根结点到叶子结点的所有路径

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

void search(TreeNode *root, string path, vector<string> &paths)
{
    if (root)
    {
        path += to_string(root->val);
        if (!root->left && !root->right)
        {
            // It's a leaf, add the path to paths
            paths.push_back(path);
        }
        else
        {
            // Not a leaf, continue the path
            path += "->";
            search(root->left, path, paths);
            search(root->right, path, paths);
        }
    }
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> paths;
    if (root)
    {
        search(root, "", paths);
    }
    return paths;
}

