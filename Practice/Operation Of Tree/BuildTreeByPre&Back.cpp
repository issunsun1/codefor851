#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
} TreeNode;

TreeNode *BuildTree(vector<int> &pre, vector<int> &post, int prestart, int preend, int poststart, int postend)
{
    if (prestart > preend)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(pre[prestart]);
    if (prestart == preend)
    { // 只有一个，直接返回
        return root;
    }
    int i = poststart;
    while (i < postend && post[i] != pre[prestart + 1])
    { // 确定分界点，左子树的根节点
        i++;
    }
    int len = i - poststart + 1; // 左子树长度
    root->left = BuildTree(pre, post, prestart + 1, prestart + len, poststart, i);
    root->right = BuildTree(pre, post, prestart + 1 + len, preend, i + 1, postend - 1);
    return root;
}

TreeNode * constructFromPrePost(vector<int> &pre, vector<int> &post)
{
    return BuildTree(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
}

