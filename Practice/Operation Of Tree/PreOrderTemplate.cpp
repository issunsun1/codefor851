#include <iostream>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

void PreOrderTravel(TreeNode *root)
{
    if(!root)
        return;

    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()||root)
    {
        while(root)
        {
            s.push(root);
            root = root->left;
        }

        TreeNode *temp = s.top();
        s.pop();

        //  对一第一个结点进行存储
        // {

        // }

        root = temp->right;
    }
    
}