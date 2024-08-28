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

vector<int> postorder(TreeNode *root)
{

    vector<int> a;
    stack<TreeNode *> s;

    if (!root)
        return a;

    TreeNode *lastvisited = nullptr;

    while(!s.empty()||!root)
    {
        if (root)
        {
            s.push(root);
            root = root->left; // 先遍历左子树
        }
        else
        {
            TreeNode *node = s.top();
            if (node->right && lastvisited != node->right)
            {
                // 如果右子节点存在并且还没有被遍历，则遍历右子树
                root = node->right;
            }
            else
            {
                a.push_back(node->val); // 如果右子节点不存在或已被遍历，记录当前节点值
                lastvisited = node;
                s.pop();
            }
        }
    }
}

int main()
{
    
    return 0;
}
