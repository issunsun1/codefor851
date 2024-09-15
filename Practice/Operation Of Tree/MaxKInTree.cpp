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
} TreeNode;

// 查找二叉搜索树中第k大的结点

int search(TreeNode *root, int k)
{
    vector<int> ans;
    stack<TreeNode *> s;

    while(root||!s.empty())
    {
        while(root)
        {
            s.push(root);
            root = root->left;
        }

        root = s.top();
        s.pop();
        ans.push_back(root->val);

        root = root->right;
    }

    return ans[ans.size() - k];
}

int main()
{
    
    return 0;
}
