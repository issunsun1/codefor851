#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

vector<int> leveltravel(TreeNode *root)
{
    vector<int> ans;
    queue<TreeNode *> q;

    if(root==nullptr)
        return ans;
    
    q.push(root);

    while(!q.empty())
    {
        root = q.front();
        q.pop();
        ans.push_back(root->val);
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }

    return ans;
}


int main()
{

    return 0;
}
