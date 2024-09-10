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

// 删除二叉树中值为key的结点
TreeNode* DeleteNode(TreeNode *root,int key)
{
    if(root==nullptr)
        return root;
    if(root->val==key)
    {
        if(root->left==nullptr)
            return root->right;
        if(root->right==nullptr)
            return root->left;

        TreeNode *maxNode = root->left;

        // 寻找左子树最大结点，即左子树最右结点
        while (maxNode)
        {
            if (maxNode->right != nullptr)
                maxNode = maxNode->right;
        }

        root->val = maxNode->val;

        root->left = DeleteNode(root->left, maxNode->val);
    }
    else if(root->val<key)
        DeleteNode(root->right, key);
    else if(root->val>key)
        DeleteNode(root->left, key);

    return root;
}

int
main()
{
    
    return 0;
}
